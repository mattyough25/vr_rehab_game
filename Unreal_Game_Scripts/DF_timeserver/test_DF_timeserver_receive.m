function test_DF_timeserver_receive
global DF

%% subscribe to DF messages
% add messages
MessageTypes =  {'SERVER_TIMESTAMP_USER','UE_VIVE_TRACKER_DATA'};  
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
tic
tTime = toc;
index = 1;

format long
while tTime < 20

    %% read data from DF
    M1           = ReadMessage(0);
    if ~isempty(M1)
        switch M1.msg_type
            case 'UE_VIVE_TRACKER_DATA'
                disp('reading data')
                %% read timeserver timestamp
                % Request Time Server Time
                nMT  = EnsureNumericMessageType('REQUEST_TIMESTAMP_USER');
                % Get Sending Time
                msg         = DF.MDF.REQUEST_TIMESTAMP_USER;
                UnsafeSendMessage( nMT, msg);
                M2           = ReadMessage('blocking');
                tTime2 = M2.data.t;
                
                if ~isempty(tTime2)
                    tTime1 = M1.data.t/1000;
                    tDFTime(index,:) = [tTime1,tTime2];
%                     
                    index = index + 1;
                    
                end
        end
    end
%         pause(0.5)
    tTime = toc;
end
%     save('G:\Shared drives\PRJ DOD RESTORE\Prototype Testing\Box And Block VR Environment\TimeStampTesting\DFTimeDelay.mat','tDFTime')
    DisconnectFromMMM
    
%     pause(600)
%     system('shutdown -s')