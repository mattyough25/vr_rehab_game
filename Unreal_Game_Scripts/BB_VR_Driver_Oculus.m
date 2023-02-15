clear
clc

global DF
sPath = cd;

%% Define Logical Variables
par.bWrite2File     = true;
par.bDF             = true;
Spawn_Block_Left = true; % True if blocks are to be spawned on the left side of the box

%% Define number of Reps, ip_address, and Subject Anthropomorphic Data
nRep = 2;
ip = ['[]'];

nForeLength    = 33; % in cm
nElbHeight     = 63;

%% Initialize File Names
sFile = sprintf('OCULUS_Array_BB_VR_1_%s.bin', datestr(now,'mm-dd-yyyy-HH-MM')); %Automated naming of Oculus
sFileLocation = ['ObjectLocationData_Set_01.csv']; % table, drop target, and block location file

%% Define Table Spawn Location
nPawnLocation = [0 0 0];%[0 0 0]; [-541 100 -85];
nTableLocation = [nPawnLocation(1)+(nForeLength/2.27) nPawnLocation(2) nPawnLocation(3)+(nElbHeight/1.02)];

% nTableLocation = [-530 100 -20];

%% Define Block Spawn Locations

% Blocks spawn on the left side of the box [(-508- -523) (79 95) (-22)]
% +7--+22
nBlock_Location_Left = [...
    nTableLocation(1)+15   nTableLocation(2)-20 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    nTableLocation(1)+15   nTableLocation(2)-13 nTableLocation(3);...
    ];

% Blocks spawn on the right side of the box [(-508- -523) (105-122) (-22)]
nBlock_Location_Right = [...
    nTableLocation(1)+20 nTableLocation(2)+19 nTableLocation(3)-2;...
    nTableLocation(1)+7 nTableLocation(2)+7  nTableLocation(3)-2;...
    nTableLocation(1)+20 nTableLocation(2)+20 nTableLocation(3)-2;...
    nTableLocation(1)+9 nTableLocation(2)+11 nTableLocation(3)-2;...
    nTableLocation(1)+18 nTableLocation(2)+12 nTableLocation(3)-2;...
    nTableLocation(1)+11 nTableLocation(2)+11 nTableLocation(3)-2;...
    nTableLocation(1)+16 nTableLocation(2)+16 nTableLocation(3)-2;...
    nTableLocation(1)+13 nTableLocation(2)+7  nTableLocation(3)-2;...
    nTableLocation(1)+14 nTableLocation(2)+19 nTableLocation(3)-2;...
    nTableLocation(1)+15  nTableLocation(2)+15 nTableLocation(3)-2;...
    nTableLocation(1)+12 nTableLocation(2)+14 nTableLocation(3)-2;...
    nTableLocation(1)+17 nTableLocation(2)+14 nTableLocation(3)-2;...
    nTableLocation(1)+10 nTableLocation(2)+12 nTableLocation(3)-2;...
    nTableLocation(1)+19 nTableLocation(2)+15 nTableLocation(3)-2;...
    nTableLocation(1)+8 nTableLocation(2)+12 nTableLocation(3)-2;...
    nTableLocation(1)+20 nTableLocation(2)+5  nTableLocation(3)-2;...
    nTableLocation(1)+6 nTableLocation(2)+7  nTableLocation(3)-2;...
    nTableLocation(1)+7 nTableLocation(2)+17 nTableLocation(3)-2;...
    nTableLocation(1)+4 nTableLocation(2)+11 nTableLocation(3)-2;...
    nTableLocation(1)+9 nTableLocation(2)+7  nTableLocation(3)-2;...
    ];

nDrop_Target_Location = [nTableLocation(1)+14 nTableLocation(2)+19.5 nTableLocation(3)-3.6; nTableLocation(1)+14 nTableLocation(2)-13 nTableLocation(3)-3.6];

%% Save table, target, and block locations to csv file
for kRep = 1:nRep
    nLocationData.idTrial(kRep) = kRep;

    nLocationData.PawnX(kRep) = nPawnLocation(1);
    nLocationData.PawnY(kRep) = nPawnLocation(2);
    nLocationData.PawnZ(kRep) = nPawnLocation(3);

    nLocationData.TableX(kRep) = nTableLocation(1);
    nLocationData.TableY(kRep) = nTableLocation(2);
    nLocationData.TableZ(kRep) = nTableLocation(3);
end

if Spawn_Block_Left
    for jRep = 1:nRep
        nLocationData.DropTargetX(jRep) = nDrop_Target_Location(1,1);
        nLocationData.DropTargetY(jRep) = nDrop_Target_Location(1,2);
        nLocationData.DropTargetZ(jRep) = nDrop_Target_Location(1,3);

        nLocationData.BlockX(jRep) = nBlock_Location_Left(jRep,1);
        nLocationData.BlockY(jRep) = nBlock_Location_Left(jRep,2);
        nLocationData.BlockZ(jRep) = nBlock_Location_Left(jRep,3);
    end
else
    for jRep = 1:nRep
        nLocationData.DropTargetX(jRep) = nDrop_Target_Location(2,1);
        nLocationData.DropTargetY(jRep) = nDrop_Target_Location(2,2);
        nLocationData.DropTargetZ(jRep) = nDrop_Target_Location(2,3);

        nLocationData.BlockX(jRep) = nBlock_Location_Right(jRep,1);
        nLocationData.BlockY(jRep) = nBlock_Location_Right(jRep,2);
        nLocationData.BlockZ(jRep) = nBlock_Location_Right(jRep,3);
    end

end

sFileLocation = avoidOverwrite_BB(sFileLocation,sPath,2,2);
save_csv(nLocationData,'sFile',sFileLocation)
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
tosend.n = 10;

%% Sending Box and Block Table Location to Unreal
if Spawn_Block_Left % Blocks will be spawned on the left side of the box
    tosend.dat = [...
        0,... % Number of reps
        nTableLocation(1),... % Table spawn x location
        nTableLocation(2),... % Table spawn y location
        nTableLocation(3),... % Table spawn z location
        nDrop_Target_Location(1,1),... % Drop Target x location
        nDrop_Target_Location(1,2),... % Drop Target y location
        nDrop_Target_Location(1,3),... % Drop Target z location
        0,... % Block x location
        0,... % Block y location
        0,... % Block z location
        ];
else % Blocks will be spawned on the right side of the box
    tosend.dat = [...
        0,... % Number of reps
        nTableLocation(1),... % Table spawn x location
        nTableLocation(2),... % Table spawn y location
        nTableLocation(3),... % Table spawn z location
        nDrop_Target_Location(2,1),... % Drop Target x location
        nDrop_Target_Location(2,2),... % Drop Target y location
        nDrop_Target_Location(2,3),... % Drop Target z location
        0,... % Block x location
        0,... % Block y location
        0,... % Block z location
        ];
end
matlab_client('send_data',tosend);

pause(1)
%% read timeserver timestamp
% Request Time Server Time
% nMT  = EnsureNumericMessageType('REQUEST_TIMESTAMP_USER');
% % Get Sending Time
% msg         = DF.MDF.REQUEST_TIMESTAMP_USER;
% UnsafeSendMessage( nMT, msg);
% tStartTime           = ReadMessage('blocking');
sTime = split(string(datetime('now','TimeZone','UTC','Format','HH:mm:ss.SSS')),":");
nTime.StartTime = (str2double(sTime(1))*3600) + (str2double(sTime(2))*60) + str2double(sTime(3));

%% Sending Data To Unreal
%Initialize Time Server Sync Values
nBlockDropTime = 0;
for iRep = 1:nRep

    %% Reading From Unreal

    if Spawn_Block_Left % Blocks will be spawned on the left side of the box
        tosend.dat = [...
            nRep,... % Number of Reps
            0,... % Table spawn x location
            0,... % Table spawn y location
            0,... % Table spawn z location
            0,... % Drop Target x location
            0,... % Drop Target y location
            0,... % Drop Target z location
            nBlock_Location_Left(iRep,1),... % Block x location
            nBlock_Location_Left(iRep,2),... % Block y location
            nBlock_Location_Left(iRep,3),... % Block z location
            ];

    else % Blocks will be spawned on the right side of the box
        tosend.dat = [...
            nRep,... % Number of Reps
            0,... % Table spawn x location
            0,... % Table spawn y location
            0,... % Table spawn z location
            0,... % Drop Target x location
            0,... % Drop Target y location
            0,... % Drop Target z location
            nBlock_Location_Right(iRep,1),... % Block x location
            nBlock_Location_Right(iRep,2),... % Block y location
            nBlock_Location_Right(iRep,3),... % Block z location
            ];

    end

    matlab_client('send_data',tosend);

    %% read timeserver timestamp
    % Request Time Server Time
%     nMT2  = EnsureNumericMessageType('REQUEST_TIMESTAMP_USER');
%     % Get Sending Time
%     msg2         = DF.MDF.REQUEST_TIMESTAMP_USER;
%     UnsafeSendMessage( nMT2, msg2);
%     tSpawnTime           = ReadMessage('blocking');
    sTime = split(string(datetime('now','TimeZone','UTC','Format','HH:mm:ss.SSS')),":");
    nTime.SpawnTime(iRep) = (str2double(sTime(1))*3600) + (str2double(sTime(2))*60) + str2double(sTime(3));

    if iRep == 1
        [nBlockDropTime(iRep),tCountTime] = wait_for_block_drop(par,iRep);
    else
        [nBlockDropTime(iRep),tCountTime2] = wait_for_block_drop(par,iRep);
        tCountTime = cat(2,tCountTime,tCountTime2);
    end
end

%% Reset Send Data
nTime.BlockDrop = nBlockDropTime;

tosend.dat = [...
    0,... % Number of Reps
    0,... % Table spawn x location
    0,... % Table spawn y location
    0,... % Table spawn z location
    0,... % Drop Target x location
    0,... % Drop Target y location
    0,... % Drop Target z location
    0,... % Block x location
    0,... % Block y location
    0,... % Block z location
    ];
matlab_client('send_data',tosend);
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
    %save(sFileEvents,'nTime');
    %
end

disp('disconnected')
