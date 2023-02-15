% This scripts forms a TCP connection
%% TCP Socket Connection
clear
clc

try
    TCP_server.ServerPort
    disp('Socket Already Connected')  
catch
    TCP_server = tcpserver("localhost",7000); % connect to tcp server
    TCP_server.Timeout = 60;
    disp('Socket Connected')
end

%%

% tMatlab =  datestr(now, 'SS:FFF');
% 
% try
%     write(TCP_server,tMatlab,"string")
% catch
%     disp('Data not sent')
% end
% try
%     tUnreal = read(TCP_server,TCP_server.NumBytesAvailable,"string");
% catch
%     disp('No Data to Read')
% end
% 
% 
