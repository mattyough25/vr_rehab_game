function send_to_DF_Leap (par, nTime, nVRData)
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