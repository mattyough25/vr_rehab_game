function [nTime,tCountTime] = wait_for_block_drop(par,iRep)

global DF

persistent nTimePrev bBlockDestroyedPrev
if isempty(nTimePrev)
    nTimePrev = 0;
    bBlockDestroyedPrev = false;
end

%% Reading Timeserver 

bSync = true;
bwait = true;

ix = 1;
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
                    %nTime = M.data.t;
                    bSync = 0; % Syncing is done
                    
            end
            %% Get Current Universal Time
            if ix == 1
                sTime = split(string(datetime('now','TimeZone','UTC','Format','HH:mm:ss.SSS')),":");
                tic
                nTime = (str2double(sTime(1))*3600) + (str2double(sTime(2))*60) + str2double(sTime(3));
            else
                nTime = nTime + toc;
            end

            tCountTime(ix) = toc;
            ix = ix + 1; 
            % set variable to make sure we only run new data
            nTimePrev 	= nVRTime;
%             nTime       = nVRTime;
      
            bBlockDestroyed 	= nVRData.dat(6);
           
            if (bBlockDestroyed == 1 && ~bBlockDestroyedPrev)
%                 if par.bWrite2File
%                     nData = nVRData.dat;
%                     [HandData] =  getHandData(nTime, nData)
% 
%                 end
                bwait = false;
                bBlockDestroyedPrev = true;

            else
                bBlockDestroyedPrev = false;
            end
            
            if par.bWrite2File
                save_the_data(par, nTime, nVRData)
                
            end
            
            if par.bDF
                send_to_DF(par, nTime,  nVRData)
            end
        end
    end
end