function test_DF_timeserver_send
global DF

%% subscribe to DF messages
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
% pause(10)

tic
runTime = toc;
format long
while runTime < 45
    %% read timeserver timestamp
    % Request Time Server Time
    nMT  = EnsureNumericMessageType('REQUEST_TIMESTAMP_USER');
    % Get Sending Time
    msg         = DF.MDF.REQUEST_TIMESTAMP_USER;
    UnsafeSendMessage( nMT, msg);
    M           = ReadMessage('blocking');
    tTime = M.data;

    %% send data to DF
    if ~isempty(tTime)
        nDAQMessage  = EnsureNumericMessageType('SERVER_TIMESTAMP_DE');
        msg2          = DF.MDF.SERVER_TIMESTAMP_DE;
        msg2.t        = tTime.t;
        
        SendMessage( nDAQMessage, msg2);
       % disp('sent message')
%         pause(0.5)
    end
    runTime = toc;
end
    DisconnectFromMMM
%     pause(60)
%     quit