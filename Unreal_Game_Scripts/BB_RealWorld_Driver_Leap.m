clear
clc

global DF 
sPath = cd;

%% Define Logical Variables
par.bWrite2File     = true;
par.bDF             = true;
bRun                = true;

%% Define ip_address
ip = ['10.3.29.179'];

%% Initialize File Names
sFile = sprintf('LEAP_Array_WristSupination_2_%s.bin', datestr(now,'mm-dd-yyyy-HH-MM-SS')); %Automated naming of real bb task

%% Initialize the Save
if par.bWrite2File

    par.fid = fopen(sFile,'wb');

end

%% Subscribe to DF messages
if par.bDF
    % add messages
    MessageTypes =  {'SERVER_TIMESTAMP_USER'};  %%Edits 10/1/19 AT
    % Messages to subscribe to DF
    ConnectArgs = {0, [], 'message_defs_wvu.mat'};
    mm_ip = ip;
    if strcmp(mm_ip, '[]')
        mm_ip = [];
    end
    if exist('mm_ip','var') && ~isempty(mm_ip)
        ConnectArgs{end+1} = ['-server_name ' mm_ip, ':7111'];
    end
    ConnectToMMM(ConnectArgs{:});
    Subscribe( MessageTypes{:});
end

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

%% Connect to Unreal
matlab_client('connect', '', '44500')
disp(' ')
disp('connected')
tosend.n = 0;


%% Collecting Leap Hand Data
if bRun
    ix = 1;

    bWaitbar = waitbar(0, 'Box and Block Task', 'Name', 'Collecting Data','CreateCancelBtn','delete(gcbf)');
    tic
    while bRun
    drawnow;



        %% read unreal data
        nDataLeap = matlab_client('request_data');
        %% read timeserver timestamp
        % Request Time Server Time
        nMT2  = EnsureNumericMessageType('REQUEST_TIMESTAMP_USER');
        % Get Sending Time
        msg2         = DF.MDF.REQUEST_TIMESTAMP_USER;
        UnsafeSendMessage( nMT2, msg2);
        M2           = ReadMessage('blocking');
        tTime = M2.data.t;

        tCountTime(ix) = toc;
        ix = ix + 1;
%         if ~isempty(tTime)
%             nLeapTime.DFTime(ix) = tTime;
%         end

        if par.bWrite2File
            save_the_data(par, tTime, nDataLeap)

        end

        if par.bDF
            send_to_DF(par, tTime,  nDataLeap)
        end

        if ~ishandle(bWaitbar)
            disp('Stopped Recording')
            break;
        end
        
    end
end
%%
matlab_client('close')

if par.bDF
    % close DF connection
    DisconnectFromMMM
end

if par.bWrite2File
    % close save the data
    fclose(par.fid);

    metaSignal = load_csv('sFile', 'metaSignal_task.csv', 'bVerbose', false);
    %unreal_bin_to_mat(sFile, 0, metaSignal)
    unreal_bin_to_mat_VR(sFile, 0, metaSignal,tCountTime)
    %save(sFileEvents,'nLeapTime');
    %
end

disp('disconnected')



