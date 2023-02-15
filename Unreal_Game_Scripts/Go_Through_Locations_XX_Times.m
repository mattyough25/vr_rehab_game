function Go_Through_Locations_XX_Times
global DF
clear wait_for_target_reached

par.bWrite2File     = true;
par.bDF             = true;
par.bSendPulse      = true;
sFile = sprintf('UNREAL_%s.bin', datestr(now,'mm-dd-yyyy-HH-MM')); %Automated naming of LEAP, keep notes on what time each trial started
sFilePar = sprintf('VR_mat_par_%s.csv', datestr(now,'mm-dd-yyyy-HH-MM')); % parameter data
sFileEvents = sprintf('TimeServerEvents_%s.mat', datestr(now,'mm-dd-yyyy-HH-MM')); % timeserver data for events
nRep            = 15;
Distance_Ratio  = 0.25; % movement distance as % of arm length
nT1_angle       = 0; % T1 angle in deg relative to trunk X axis, forward = 0 deg; rightward = 270 deg
nBallSize       = 4; % ball diameter in cm
nPinchThreshold = 2; % pinch distance threshold for VR event detection
tReachThreshold = 0.5 + 0.2 + 0.5; % overall movement duration that we want in seconds, outward + T1 delay + inward
tReachVar       = 0.3; % reaching movement duration variance tolerance
bPlot           = 1;

%% Shoulder,Elbow,and Hand locations [x,y,z] in cm
nShLoc      = [3,-30,107]'; % in cm
nElbLoc     = [10,-34,73]';
nHandLoc    = [54,-30,74]';

nUpperArm   = sqrt((nShLoc(1)-nElbLoc(1))^2 + (nShLoc(2)-nElbLoc(2))^2 + (nShLoc(3)-nElbLoc(3))^2);
nLowerArm   = sqrt((nHandLoc(1)-nElbLoc(1))^2 + (nHandLoc(2)-nElbLoc(2))^2 + (nHandLoc(3)-nElbLoc(3))^2);
nArm        = (nUpperArm + nLowerArm)/100; %Arm Length in m

%% Define Ball locations
nElbLocR = [nElbLoc(1);-nElbLoc(2);nElbLoc(3)]/100;
nHandLocR = [nHandLoc(1);-nHandLoc(2);nHandLoc(3)]/100;
[a,R] = getTrunkOrientation(nElbLocR,nHandLocR,'bPlot',bPlot);

nBall_Center = nHandLoc;  % Center ball
nBall_OuterRL = [nArm*Distance_Ratio*cosd(nT1_angle);nArm*Distance_Ratio*sind(nT1_angle);0];
nBall_OuterR =(R*nBall_OuterRL); % cm
nBall_Outer = [nBall_OuterR(1)*100 + nBall_Center(1);-nBall_OuterR(2)*100 + nBall_Center(2);nBall_OuterR(3)*100 + nBall_Center(3)];
if bPlot
    hold on
    plot3(nHandLocR(1),nHandLocR(2),nHandLocR(3),'ko')
    plot3(nBall_OuterR(1)+nHandLocR(1),nBall_OuterR(2)+nHandLocR(2),nBall_OuterR(3)+nHandLocR(3),'bo')
end

%% Manual Ball Locations
%nBall_Center = [55,-2,73]';%Center
%nBall_Outer = [75,-2,73]';%Forward
%nBall_Outer = [55,-22,73]';%Side

%% randomize target presentation
nBallOrder = [];
for iRep = 1:nRep
    
    nBallOrder = [nBallOrder, nBall_Outer];
end

nRandomize  = randperm(numel(nBallOrder(1,:)));
nBallOrder  = nBallOrder(:,nRandomize);
%%
if par.bWrite2File
    % initialize the save
    
    par.fid = fopen(sFile,'wb');
end

if par.bDF
    % add messages
    MessageTypes =  {'SERVER_TIMESTAMP_USER'};  %%Edits 10/1/19 AT
    % Messages to subscribe to DF
    ConnectArgs = {0, [], 'message_defs_wvu.mat'};
    mm_ip = choose_ip_address;
    if strcmp(mm_ip, '[]')
        mm_ip = [];
    end
    if exist('mm_ip','var') && ~isempty(mm_ip)
        ConnectArgs{end+1} = ['-server_name ' mm_ip, ':7111'];
    end
    ConnectToMMM(ConnectArgs{:});
    Subscribe( MessageTypes{:});
end

% get first ACKNOWLEDGE signal from Dragonfly to establish connection is
% complete


% Reading UNREAL
bStart = 0;
if par.bDF
    while bStart ~= numel(MessageTypes)
        % Read from DragonFly
        M           = ReadMessage(0);
        if ~isempty(M)
            switch M.msg_type
                case 'ACKNOWLEDGE'
                    bStart = bStart+1;
            end
        end
    end
    disp('Connected to Dragonfly.')
end



%% connecting to Unreal
matlab_client('connect', '', '44500')
disp(' ')
disp('connected')
tosend.n = 16;      % variable definition for Unreal


%Setting the initial location and colors
nTimeStamps = zeros(nRep,2);

%Initialize Time Server Sync Values
nTime = zeros(nRep,3);

for iRep = 1:nRep % iterate trial number
    nColor1         = 3; % yellow
    nColor2         = 3; % yellow
    idTargetball    = 1;
    
    % show center ball and set both target locations
    tosend.dat  = [...
        0,...               % using PhaseSpace (0 = not using, 1 = using)
        1,...               % touch targets with PhaseSpace (1 = Leap, 0 = PhaseSpace)
        0,...               % PhaseSpace Visible? ( 0 = Not Visible, 1 = Visible)
        1,...               % Leap Visible? ( 0 = Not Visible, 1 = Visible)
        nBall_Center(1),... % Ball 1 x Location
        nBall_Center(2),... % Ball 1 y Location
        nBall_Center(3),... % Ball 1 z Location
        nColor1,...         % Ball 1 color id
        nBallSize,...       % Ball 1 size in cm
        1,...               % Ball 1 visibility
        nBall_Outer(1),...  % Ball 2 x Location
        nBall_Outer(2),...  % Ball 2 y Location
        nBall_Outer(3),...  % Ball 2 z Location
        nColor2,...         % Ball 2 color id
        nBallSize,...       % Ball 2 size in cm
        0                   % Ball 2 visibility
        ];
    matlab_client('send_data', tosend);
    
    % detect target event
    [nTime(iRep,1)] = wait_for_target_reached(par,idTargetball,nPinchThreshold);
    if par.bSendPulse % set T0 timestamp to Dragonfly
        CheckMessageTypeExist( 'SEND_PULSE_TO_NI')
        nPulseMessage       = 'SEND_PULSE_TO_NI';
        %             nPulseMessage     = EnsureNumericMessageType('SEND_PULSE_TO_NI');
        msg                 = DF.MDF.SEND_PULSE_TO_NI;
        msg.bTrigger      	= int32(1);
        msg.sTargetType     = char('T000000000');
        msg.sEventType      = char('Pinch00000');
        UnsafeSendMessage( 126, msg);
        disp('Center Detected');
    end
    
    % show outer ball
    idTargetball    = 2;
    tosend.dat(10)  = 0;    % Ball 1 visibility
    tosend.dat(16)  = 1;    % Ball 2 visibility
    matlab_client('send_data', tosend);
    tCue = tic;             % start timer for reach duration
    
    % detect target event
    [nTime(iRep,2)] =wait_for_target_reached(par,idTargetball,nPinchThreshold);
    if par.bSendPulse % set T1 timestamp to Dragonfly
        CheckMessageTypeExist( 'SEND_PULSE_TO_NI')
        nPulseMessage       = 'SEND_PULSE_TO_NI';
        %             nPulseMessage     = EnsureNumericMessageType('SEND_PULSE_TO_NI');
        msg                 = DF.MDF.SEND_PULSE_TO_NI;
        msg.bTrigger      	= int32(1);
        msg.sTargetType     = char('T100000000');
        msg.sEventType      = char('Pinch00000');
        UnsafeSendMessage(126, msg);
        disp('T1 Detected');
    end
    
    % show center ball
    idTargetball    = 1;
    tosend.dat(10)  = 1;    % Ball 1 visibility
    tosend.dat(16)  = 0;    % Ball 2 visibility
    matlab_client('send_data', tosend);
    
    % detect target event
    [nTime(iRep,3)] = wait_for_target_reached(par,idTargetball,nPinchThreshold);
    tReach = toc(tCue);     % measure reach duration
    if par.bSendPulse % set T0 timestamp to Dragonfly
        CheckMessageTypeExist( 'SEND_PULSE_TO_NI')
        nPulseMessage       = 'SEND_PULSE_TO_NI';
        %             nPulseMessage     = EnsureNumericMessageType('SEND_PULSE_TO_NI');
        msg                 = DF.MDF.SEND_PULSE_TO_NI;
        msg.bTrigger      	= int32(1);
        msg.sTargetType     = char('T200000000');
        msg.sEventType      = char('Pinch00000');
        UnsafeSendMessage( 126, msg);
        disp('Center Detected');
    end
    
    % give visual feedback about speed
    if tReach > tReachThreshold + tReachVar
        nColor1 = 2;            % red
    elseif tReach < tReachThreshold - tReachVar
        nColor1 = 0;            % blue
    else
        nColor1 = 1; % green
    end
    tosend.dat(8)  = nColor1;    % Ball 1 color
    matlab_client('send_data', tosend);
    pause(0.5)
    nTimeStamps(iRep,:) = [tCue,tReach];
end
matlab_client('close')

if par.bDF
    % close DF connection
    DisconnectFromMMM
end

if par.bWrite2File
    % close save the data
    fclose(par.fid);
    
    addpath([getenv('NE_REPOSITORIES'), 'daq_systems' filesep 'Unreal Engine', filesep])
    
    metaSignal = load_csv('sFile', 'metaSignal_task.csv', 'bVerbose', false);
    %unreal_bin_to_mat(sFile, 0, metaSignal)
    unreal_bin_to_mat_boxsci(sFile, 0, metaSignal)
    save(sFileEvents,'nTime');
%     
end

disp('disconnected')


%% save parameters

metaPar.nRep            = nRep;
metaPar.nDistanceRatio  = Distance_Ratio; % movement distance as % of arm length
metaPar.nT1_angle       = nT1_angle; % T1 angle in deg relative to trunk X axis, forward = 0 deg; rightward = 270 deg
metaPar.nBallSize       = nBallSize; % ball diameter in cm
metaPar.nPinchThreshold = nPinchThreshold; % pinchign threshodl in cm
metaPar.nShLoc          = nShLoc; % in cm
metaPar.nElbLoc         = nElbLoc;  % in cm
metaPar.nHandLoc        = nHandLoc;  % in cm
metaPar.nUpperArm       = nUpperArm;% in cm
metaPar.nLowerArm       = nLowerArm;% in cm
metaPar.nTrunkAngle     = a; % in deg
metaPar.nTrunkR         = R;
metaPar.nBall_Center    = nBall_Center;  % T0 ball location in cm
metaPar.nBall_Outer     = nBall_Outer;% T1 ball location in cm
metaPar.tReachThreshold = tReachThreshold;
metaPar.tReachVar       = tReachVar;
metaPar.nTimeStamps     = nTimeStamps; % Reach timestamps used for color feedback
save_csv(metaPar,'sFile',sFilePar)
disp(['saved parameters in',sFilePar])

function [nTime] = wait_for_target_reached(par,idTargetball,nPinchThreshold)
global DF

persistent nTimePrev bTargetReachedPrev
if isempty(nTimePrev)
    nTimePrev = 0;
    bTargetReachedPrev = false;
end

%% Reading Timeserver 

bSync = true;
bwait = true;

while bwait
    drawnow;
    %read data from unreal
    nVRData = matlab_client('request_data');
    if nVRData.n ~= 0
        nVRTime     = nVRData.dat(1);
        % check that data is new
        if nVRTime ~= nTimePrev
            
            % Request Time Server Time
            nMT  = EnsureNumericMessageType('REQUEST_TIMESTAMP_USER');
            % Get Sending Time
            msg         = DF.MDF.REQUEST_TIMESTAMP_USER;
            UnsafeSendMessage( nMT, msg);
            
            M           = ReadMessage('blocking');
            switch M.msg_type
                case 'SERVER_TIMESTAMP_USER'
                    nTime = M.data.t;
                    bSync = 0; % Syncing is done
            end
            % set variable to make sure we only run new data
            nTimePrev 	= nVRTime;
%             nTime       = nVRTime;
            
            
            
            
            
            ixBeginingTaskData = 5 + sum(nVRData.dat(2:4));
            bTargetReached 	= nVRData.dat(ixBeginingTaskData+idTargetball);
            
            nPinchDistance = nVRData.dat(ixBeginingTaskData+3);
            
            if nPinchDistance < nPinchThreshold
                bPinched = true;
            else
                bPinched = false;
            end
            if (bTargetReached == 1 && ~bTargetReachedPrev) && bPinched
                bwait = false;
                bTargetReachedPrev = true;       
                
            else
                bTargetReachedPrev = false;
            end
            
            if par.bWrite2File
                save_the_data(par, nTime, nVRData)
                
            end
            
            if par.bDF
                send_to_DF (par,nTime,  nVRData)
            end
        end
    end
    
end

function send_to_DF (par, nTime, nVRData)
global DF
persistent nMT

if isempty(nMT)
    nMT  = EnsureNumericMessageType('REACHING_UNREAL_DATA');
end

if par.bDF
    % Start the data index
    ix = 5; % initialize index
    
    % Check if there is Tracker data
    if nVRData.dat(2) > 0
        
        nDAQMessage  = EnsureNumericMessageType('UE_VIVE_TRACKER_DATA');
        msg             = DF.MDF.UE_VIVE_TRACKER_DATA;
        msg.t           = single(nTime);
        
        numTracker                          = nVRData.dat(2)/7;
        msg.nViveTrackerLocX(1:numTracker)  = single(nVRData.dat((1:7:numTracker*7)+ix));
        msg.nViveTrackerLocY(1:numTracker)	= single(nVRData.dat((2:7:numTracker*7)+ix));
        msg.nViveTrackerLocZ(1:numTracker)	= single(nVRData.dat((3:7:numTracker*7)+ix));
        msg.nViveTrackerRotX(1:numTracker)	= single(nVRData.dat((4:7:numTracker*7)+ix));
        msg.nViveTrackerRotY(1:numTracker)	= single(nVRData.dat((5:7:numTracker*7)+ix));
        msg.nViveTrackerRotZ(1:numTracker)	= single(nVRData.dat((6:7:numTracker*7)+ix));
        
        SendMessage( nDAQMessage, msg);
        %                 UnsafeSendMessage( nDAQMessage, msg);
    end
    
    % Add the vive data if any to the index
    % nVRData.dat(2) will = 0 if there is no vive data
    ix = ix + nVRData.dat(2);
    
    % Check if there is Leap data
    if nVRData.dat(3) > 0
        nDAQMessage     = EnsureNumericMessageType('UE_LEAP_DATA');
        msg             = DF.MDF.UE_LEAP_DATA;
        msg.t           = single(nTime);
        
        %This is not correct labelling, but will need to change message
        %types in order to change
        
        
        msg.WristLocX      	= single(nVRData.dat(ix));
        msg.WristLocY      	= single(nVRData.dat(ix+1));
        msg.WristLocZ       = single(nVRData.dat(ix+2));
        msg.UnknownLocX    	= single(nVRData.dat(ix+3));
        msg.UnknownLocY   	= single(nVRData.dat(ix+4));
        msg.UnknwonLocZ    	= single(nVRData.dat(ix+5));
        msg.ThumbLocX      	= single(nVRData.dat((1:15:60)+ix+6-1)');
        msg.ThumbLocY      	= single(nVRData.dat((2:15:60)+ix+6-1)');
        msg.ThumbLocZ      	= single(nVRData.dat((3:15:60)+ix+6-1)');
        msg.IndexLocX      	= single(nVRData.dat((4:15:60)+ix+6-1)');
        msg.IndexLocY     	= single(nVRData.dat((5:15:60)+ix+6-1)');
        msg.IndexLocZ      	= single(nVRData.dat((6:15:60)+ix+6-1)');
        msg.MiddleLocX    	= single(nVRData.dat((7:15:60)+ix+6-1)');
        msg.MiddleLocY   	= single(nVRData.dat((8:15:60)+ix+6-1)');
        msg.MiddleLocZ     	= single(nVRData.dat((9:15:60)+ix+6-1)');
        msg.RingLocX      	= single(nVRData.dat((10:15:60)+ix+6-1)');
        msg.RingLocY      	= single(nVRData.dat((11:15:60)+ix+6-1)');
        msg.RingLocZ      	= single(nVRData.dat((12:15:60)+ix+6-1)');
        msg.PinkyLocX     	= single(nVRData.dat((13:15:60)+ix+6-1)');
        msg.PinkyLocY       = single(nVRData.dat((14:15:60)+ix+6-1)');
        msg.PinkyLocZ    	= single(nVRData.dat((15:15:60)+ix+6-1)');
        
        SendMessage( nDAQMessage, msg);
        
        
    end
    
    % Add the Leap data if any to the index
    % nVRData.dat(3) will = 0 if there is no Leap data
    ix = ix + nVRData.dat(3);
    
    % check if there is phasespace data
    if nVRData.dat(4) > 0
        % do something with PhaseSpace Data if wanted
        
    end
    
    
    % Add the PhaseSpace data if any to the index
    % nVRData.dat(4) will = 0 if there is no PhaseSpace data
    ix = ix + nVRData.dat(4);
    
    % check if there is task specific data
    if nVRData.dat(5) > 0
        nDAQMessage  = EnsureNumericMessageType('REACHING_UNREAL_DATA');
        msg             = DF.MDF.REACHING_UNREAL_DATA;
        msg.t           = single(nTime);
        
        msg.bTargetReached 	= single(nVRData.dat((1:2)+ix)');
        
        SendMessage( nDAQMessage, msg);
    end
end

function save_the_data(par, nTime, nVRData)

fwrite(par.fid,[nTime; nVRData.dat(2:end)],'single');
