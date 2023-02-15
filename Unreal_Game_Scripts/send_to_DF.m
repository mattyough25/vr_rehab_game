function send_to_DF (par, nTime, nVRData)
global DF
persistent nMT

if isempty(nMT)
    nMT  = EnsureNumericMessageType('UE_BOX_AND_BLOCK_DATA');
end

if par.bDF
    % Start the data index
    ix = 5; % initialize index
    
    % Check if there is block data
    if nVRData.dat(2) > 0
        
        nDAQMessage  = EnsureNumericMessageType('BLOCK_DESTROYED');
        msg             = DF.MDF.BLOCK_DESTROYED;
        msg.t           = single(nTime);
        
        
        UnsafeSendMessage( nDAQMessage, msg);
        
        msg.bBlockDestroyed = single(nVRData.dat(ix+1,:));
    end
    % Add the hand data if any to the index
    % nVRData.dat(2) will = 0 if there is no hand data
    ix = ix + nVRData.dat(2);
    
    % Check if there is left hand data
    if nVRData.dat(3) > 0
        nDAQMessage     = EnsureNumericMessageType('OCULUS_LEFT_HAND_DATA');
        msg             = DF.MDF.OCULUS_LEFT_HAND_DATA;
        msg.t           = single(nTime);
        
        % Left Hand
        msg.la_wr_x = single(nVRData.dat(ix+1,:)); msg.la_wr_y = single(nVRData.dat(ix+2,:)); msg.la_wr_z = single(nVRData.dat(ix+3,:));
        msg.la_wr_roll = single(nVRData.dat(ix+4,:)); msg.la_wr_pitch = single(nVRData.dat(ix+5,:)); msg.la_wr_yaw = single(nVRData.dat(ix+6,:));
        msg.la_cmc1_x = single(nVRData.dat(ix+7,:)); msg.la_cmc1_y = single(nVRData.dat(ix+8,:)); msg.la_cmc1_z = single(nVRData.dat(ix+9,:));
        msg.la_cmc1_roll = single(nVRData.dat(ix+10,:)); msg.la_cmc1_pitch = single(nVRData.dat(ix+11,:)); msg.la_cmc1_yaw = single(nVRData.dat(ix+12,:));
        msg.la_mcp1_x = single(nVRData.dat(ix+13,:)); msg.la_mcp1_y = single(nVRData.dat(ix+14,:)); msg.la_mcp1_z = single(nVRData.dat(ix+15,:));
        msg.la_mcp1_roll = single(nVRData.dat(ix+16,:));msg.la_mcp1_pitch = single(nVRData.dat(ix+17,:)); msg.la_mcp1_yaw = single(nVRData.dat(ix+18,:));
        msg.la_ip1_x = single(nVRData.dat(ix+19,:)); msg.la_ip1_y = single(nVRData.dat(ix+20,:)); msg.la_ip1_z = single(nVRData.dat(ix+21,:));
        msg.la_ip1_roll = single(nVRData.dat(ix+22,:)); msg.la_ip1_pitch = single(nVRData.dat(ix+23,:)); msg.la_ip1_yaw = single(nVRData.dat(ix+24,:));
        msg.la_tip1_x = single(nVRData.dat(ix+25,:)); msg.la_tip1_y = single(nVRData.dat(ix+26,:)); msg.la_tip1_z = single(nVRData.dat(ix+27,:));
        msg.la_tip1_roll = single(nVRData.dat(ix+28,:)); msg.la_tip1_pitch = single(nVRData.dat(ix+29,:)); msg.la_tip1_yaw = single(nVRData.dat(ix+30,:));
        msg.la_mcp2_x = single(nVRData.dat(ix+31,:)); msg.la_mcp2_y = single(nVRData.dat(ix+32,:)); msg.la_mcp2_z = single(nVRData.dat(ix+33,:));
        msg.la_mcp2_roll = single(nVRData.dat(ix+34,:)); msg.la_mcp2_pitch = single(nVRData.dat(ix+35,:)); msg.la_mcp2_yaw = single(nVRData.dat(ix+36,:));
        msg.la_pip2_x = single(nVRData.dat(ix+37,:)); msg.la_pip2_y = single(nVRData.dat(ix+38,:)); msg.la_pip2_z = single(nVRData.dat(ix+39,:));
        msg.la_pip2_roll = single(nVRData.dat(ix+40,:)); msg.la_pip2_pitch = single(nVRData.dat(ix+41,:)); msg.la_pip2_yaw = single(nVRData.dat(ix+42,:));
        msg.la_dip2_x = single(nVRData.dat(ix+43,:)); msg.la_dip2_y = single(nVRData.dat(ix+44,:)); msg.la_dip2_z = single(nVRData.dat(ix+45,:));
        msg.la_dip2_roll = single(nVRData.dat(ix+46,:)); msg.la_dip2_pitch = single(nVRData.dat(ix+47,:)); msg.la_dip2_yaw = single(nVRData.dat(ix+48,:));
        msg.la_tip2_x = single(nVRData.dat(ix+49,:)); msg.la_tip2_y = single(nVRData.dat(ix+50,:)); msg.la_tip2_z = single(nVRData.dat(ix+51,:));
        msg.la_tip2_roll = single(nVRData.dat(ix+52,:)); msg.la_tip2_pitch = single(nVRData.dat(ix+53,:)); msg.la_tip2_yaw = single(nVRData.dat(ix+54,:));
        msg.la_mcp3_x = single(nVRData.dat(ix+55,:)); msg.la_mcp3_y = single(nVRData.dat(ix+56,:)); msg.la_mcp3_z = single(nVRData.dat(ix+57,:));
        msg.la_mcp3_roll = single(nVRData.dat(ix+58,:));msg.la_mcp3_pitch = single(nVRData.dat(ix+59,:)); msg.la_mcp3_yaw = single(nVRData.dat(ix+60,:));
        msg.la_pip3_x = single(nVRData.dat(ix+61,:)); msg.la_pip3_y = single(nVRData.dat(ix+62,:)); msg.la_pip3_z = single(nVRData.dat(ix+63,:));
        msg.la_pip3_roll = single(nVRData.dat(ix+64,:)); msg.la_pip3_pitch = single(nVRData.dat(ix+65,:)); msg.la_pip3_yaw = single(nVRData.dat(ix+66,:));
        msg.la_dip3_x = single(nVRData.dat(ix+67,:)); msg.la_dip3_y = single(nVRData.dat(ix+68,:)); msg.la_dip3_z = single(nVRData.dat(ix+69,:));
        msg.la_dip3_roll = single(nVRData.dat(ix+70,:)); msg.la_dip3_pitch = single(nVRData.dat(ix+71,:)); msg.la_dip3_yaw = single(nVRData.dat(ix+72,:));
        msg.la_tip3_x = single(nVRData.dat(ix+73,:)); msg.la_tip3_y = single(nVRData.dat(ix+74,:)); msg.la_tip3_z = single(nVRData.dat(ix+75,:));
        msg.la_tip3_roll = single(nVRData.dat(ix+76,:)); msg.la_tip3_pitch = single(nVRData.dat(ix+77,:)); msg.la_tip3_yaw = single(nVRData.dat(ix+78,:));
        msg.la_mcp4_x = single(nVRData.dat(ix+79,:));msg.la_mcp4_y = single(nVRData.dat(ix+80,:)); msg.la_mcp4_z = single(nVRData.dat(ix+81,:));
        msg.la_mcp4_roll = single(nVRData.dat(ix+82,:)); msg.la_mcp4_pitch = single(nVRData.dat(ix+83,:)); msg.la_mcp4_yaw = single(nVRData.dat(ix+84,:));
        msg.la_pip4_x = single(nVRData.dat(ix+85,:)); msg.la_pip4_y = single(nVRData.dat(ix+86,:)); msg.la_pip4_z = single(nVRData.dat(ix+87,:));
        msg.la_pip4_roll = single(nVRData.dat(ix+88,:)); msg.la_pip4_pitch = single(nVRData.dat(ix+89,:)); msg.la_pip4_yaw = single(nVRData.dat(ix+90,:));
        msg.la_dip4_x = single(nVRData.dat(ix+91,:)); msg.la_dip4_y = single(nVRData.dat(ix+92,:)); msg.la_dip4_z = single(nVRData.dat(ix+93,:));
        msg.la_dip4_roll = single(nVRData.dat(ix+94,:)); msg.la_dip4_pitch = single(nVRData.dat(ix+95,:)); msg.la_dip4_yaw = single(nVRData.dat(ix+96,:));
        msg.la_tip4_x = single(nVRData.dat(ix+97,:)); msg.la_tip4_y = single(nVRData.dat(ix+98,:)); msg.la_tip4_z = single(nVRData.dat(ix+99,:));
        msg.la_tip4_roll = single(nVRData.dat(ix+100,:)); msg.la_tip4_pitch = single(nVRData.dat(ix+101,:)); msg.la_tip4_yaw = single(nVRData.dat(ix+102,:));
        msg.la_mcp5_x = single(nVRData.dat(ix+103,:)); msg.la_mcp5_y = single(nVRData.dat(ix+104,:)); msg.la_mcp5_z = single(nVRData.dat(ix+105,:));
        msg.la_mcp5_roll = single(nVRData.dat(ix+106,:)); msg.la_mcp5_pitch = single(nVRData.dat(ix+107,:)); msg.la_mcp5_yaw = single(nVRData.dat(ix+108,:));
        msg.la_pip5_x = single(nVRData.dat(ix+109,:)); msg.la_pip5_y = single(nVRData.dat(ix+110,:)); msg.la_pip5_z = single(nVRData.dat(ix+111,:));
        msg.la_pip5_roll = single(nVRData.dat(ix+112,:)); msg.la_pip5_pitch = single(nVRData.dat(ix+113,:)); msg.la_pip5_yaw = single(nVRData.dat(ix+114,:));
        msg.la_dip5_x = single(nVRData.dat(ix+115,:)); msg.la_dip5_y = single(nVRData.dat(ix+116,:)); msg.la_dip5_z = single(nVRData.dat(ix+117,:));
        msg.la_dip5_roll = single(nVRData.dat(ix+118,:)); msg.la_dip5_pitch = single(nVRData.dat(ix+119,:)); msg.la_dip5_yaw = single(nVRData.dat(ix+120,:));
        msg.la_tip5_x = single(nVRData.dat(ix+121,:)); msg.la_tip5_y = single(nVRData.dat(ix+122,:)); msg.la_tip5_z = single(nVRData.dat(ix+123,:));
        msg.la_tip5_roll = single(nVRData.dat(ix+124,:)); msg.la_tip5_pitch = single(nVRData.dat(ix+125,:)); msg.la_tip5_yaw = single(nVRData.dat(ix+126,:));
        
        SendMessage( nDAQMessage, msg);
    end
    % Add the left hand data if any to the index
    % nVRData.dat(3) will = 0 if there is no right hand data
    ix = ix + nVRData.dat(3);
    
    % check if there is right hand data
    if nVRData.dat(4) > 0
        nDAQMessage     = EnsureNumericMessageType('OCULUS_RIGHT_HAND_DATA');
        msg             = DF.MDF.OCULUS_RIGHT_HAND_DATA;
        msg.t           = single(nTime);
        
        %Right Hand
        msg.ra_wr_x = single(nVRData.dat(ix+1,:)); msg.ra_wr_y = single(nVRData.dat(ix+2,:)); msg.ra_wr_z = single(nVRData.dat(ix+3,:));
        msg.ra_wr_roll = single(nVRData.dat(ix+4,:)); msg.ra_wr_pitch = single(nVRData.dat(ix+5,:)); msg.ra_wr_yaw = single(nVRData.dat(ix+6,:));
        msg.ra_cmc1_x = single(nVRData.dat(ix+7,:)); msg.ra_cmc1_y = single(nVRData.dat(ix+8,:)); msg.ra_cmc1_z = single(nVRData.dat(ix+9,:));
        msg.ra_cmc1_roll = single(nVRData.dat(ix+10,:)); msg.ra_cmc1_pitch = single(nVRData.dat(ix+11,:)); msg.ra_cmc1_yaw = single(nVRData.dat(ix+12,:));
        msg.ra_mcp1_x = single(nVRData.dat(ix+13,:)); msg.ra_mcp1_y = single(nVRData.dat(ix+14,:)); msg.ra_mcp1_z = single(nVRData.dat(ix+15,:));
        msg.ra_mcp1_roll = single(nVRData.dat(ix+16,:));msg.ra_mcp1_pitch = single(nVRData.dat(ix+17,:)); msg.ra_mcp1_yaw = single(nVRData.dat(ix+18,:));
        msg.ra_ip1_x = single(nVRData.dat(ix+19,:)); msg.ra_ip1_y = single(nVRData.dat(ix+20,:)); msg.ra_ip1_z = single(nVRData.dat(ix+21,:));
        msg.ra_ip1_roll = single(nVRData.dat(ix+22,:)); msg.ra_ip1_pitch = single(nVRData.dat(ix+23,:)); msg.ra_ip1_yaw = single(nVRData.dat(ix+24,:));
        msg.ra_tip1_x = single(nVRData.dat(ix+25,:)); msg.ra_tip1_y = single(nVRData.dat(ix+26,:)); msg.ra_tip1_z = single(nVRData.dat(ix+27,:));
        msg.ra_tip1_roll = single(nVRData.dat(ix+28,:)); msg.ra_tip1_pitch = single(nVRData.dat(ix+29,:)); msg.ra_tip1_yaw = single(nVRData.dat(ix+30,:));
        msg.ra_mcp2_x = single(nVRData.dat(ix+31,:)); msg.ra_mcp2_y = single(nVRData.dat(ix+32,:)); msg.ra_mcp2_z = single(nVRData.dat(ix+33,:));
        msg.ra_mcp2_roll = single(nVRData.dat(ix+34,:)); msg.ra_mcp2_pitch = single(nVRData.dat(ix+35,:)); msg.ra_mcp2_yaw = single(nVRData.dat(ix+36,:));
        msg.ra_pip2_x = single(nVRData.dat(ix+37,:)); msg.ra_pip2_y = single(nVRData.dat(ix+38,:)); msg.ra_pip2_z = single(nVRData.dat(ix+39,:));
        msg.ra_pip2_roll = single(nVRData.dat(ix+40,:)); msg.ra_pip2_pitch = single(nVRData.dat(ix+41,:)); msg.ra_pip2_yaw = single(nVRData.dat(ix+42,:));
        msg.ra_dip2_x = single(nVRData.dat(ix+43,:)); msg.ra_dip2_y = single(nVRData.dat(ix+44,:)); msg.ra_dip2_z = single(nVRData.dat(ix+45,:));
        msg.ra_dip2_roll = single(nVRData.dat(ix+46,:)); msg.ra_dip2_pitch = single(nVRData.dat(ix+47,:)); msg.ra_dip2_yaw = single(nVRData.dat(ix+48,:));
        msg.ra_tip2_x = single(nVRData.dat(ix+49,:)); msg.ra_tip2_y = single(nVRData.dat(ix+50,:)); msg.ra_tip2_z = single(nVRData.dat(ix+51,:));
        msg.ra_tip2_roll = single(nVRData.dat(ix+52,:)); msg.ra_tip2_pitch = single(nVRData.dat(ix+53,:)); msg.ra_tip2_yaw = single(nVRData.dat(ix+54,:));
        msg.ra_mcp3_x = single(nVRData.dat(ix+55,:)); msg.ra_mcp3_y = single(nVRData.dat(ix+56,:)); msg.ra_mcp3_z = single(nVRData.dat(ix+57,:));
        msg.ra_mcp3_roll = single(nVRData.dat(ix+58,:));msg.ra_mcp3_pitch = single(nVRData.dat(ix+59,:)); msg.ra_mcp3_yaw = single(nVRData.dat(ix+60,:));
        msg.ra_pip3_x = single(nVRData.dat(ix+61,:)); msg.ra_pip3_y = single(nVRData.dat(ix+62,:)); msg.ra_pip3_z = single(nVRData.dat(ix+63,:));
        msg.ra_pip3_roll = single(nVRData.dat(ix+64,:)); msg.ra_pip3_pitch = single(nVRData.dat(ix+65,:)); msg.ra_pip3_yaw = single(nVRData.dat(ix+66,:));
        msg.ra_dip3_x = single(nVRData.dat(ix+67,:)); msg.ra_dip3_y = single(nVRData.dat(ix+68,:)); msg.ra_dip3_z = single(nVRData.dat(ix+69,:));
        msg.ra_dip3_roll = single(nVRData.dat(ix+70,:)); msg.ra_dip3_pitch = single(nVRData.dat(ix+71,:)); msg.ra_dip3_yaw = single(nVRData.dat(ix+72,:));
        msg.ra_tip3_x = single(nVRData.dat(ix+73,:)); msg.ra_tip3_y = single(nVRData.dat(ix+74,:)); msg.ra_tip3_z = single(nVRData.dat(ix+75,:));
        msg.ra_tip3_roll = single(nVRData.dat(ix+76,:)); msg.ra_tip3_pitch = single(nVRData.dat(ix+77,:)); msg.ra_tip3_yaw = single(nVRData.dat(ix+78,:));
        msg.ra_mcp4_x = single(nVRData.dat(ix+79,:));msg.ra_mcp4_y = single(nVRData.dat(ix+80,:)); msg.ra_mcp4_z = single(nVRData.dat(ix+81,:));
        msg.ra_mcp4_roll = single(nVRData.dat(ix+82,:)); msg.ra_mcp4_pitch = single(nVRData.dat(ix+83,:)); msg.ra_mcp4_yaw = single(nVRData.dat(ix+84,:));
        msg.ra_pip4_x = single(nVRData.dat(ix+85,:)); msg.ra_pip4_y = single(nVRData.dat(ix+86,:)); msg.ra_pip4_z = single(nVRData.dat(ix+87,:));
        msg.ra_pip4_roll = single(nVRData.dat(ix+88,:)); msg.ra_pip4_pitch = single(nVRData.dat(ix+89,:)); msg.ra_pip4_yaw = single(nVRData.dat(ix+90,:));
        msg.ra_dip4_x = single(nVRData.dat(ix+91,:)); msg.ra_dip4_y = single(nVRData.dat(ix+92,:)); msg.ra_dip4_z = single(nVRData.dat(ix+93,:));
        msg.ra_dip4_roll = single(nVRData.dat(ix+94,:)); msg.ra_dip4_pitch = single(nVRData.dat(ix+95,:)); msg.ra_dip4_yaw = single(nVRData.dat(ix+96,:));
        msg.ra_tip4_x = single(nVRData.dat(ix+97,:)); msg.ra_tip4_y = single(nVRData.dat(ix+98,:)); msg.ra_tip4_z = single(nVRData.dat(ix+99,:));
        msg.ra_tip4_roll = single(nVRData.dat(ix+100,:)); msg.ra_tip4_pitch = single(nVRData.dat(ix+101,:)); msg.ra_tip4_yaw = single(nVRData.dat(ix+102,:));
        msg.ra_mcp5_x = single(nVRData.dat(ix+103,:)); msg.ra_mcp5_y = single(nVRData.dat(ix+104,:)); msg.ra_mcp5_z = single(nVRData.dat(ix+105,:));
        msg.ra_mcp5_roll = single(nVRData.dat(ix+106,:)); msg.ra_mcp5_pitch = single(nVRData.dat(ix+107,:)); msg.ra_mcp5_yaw = single(nVRData.dat(ix+108,:));
        msg.ra_pip5_x = single(nVRData.dat(ix+109,:)); msg.ra_pip5_y = single(nVRData.dat(ix+110,:)); msg.ra_pip5_z = single(nVRData.dat(ix+111,:));
        msg.ra_pip5_roll = single(nVRData.dat(ix+112,:)); msg.ra_pip5_pitch = single(nVRData.dat(ix+113,:)); msg.ra_pip5_yaw = single(nVRData.dat(ix+114,:));
        msg.ra_dip5_x = single(nVRData.dat(ix+115,:)); msg.ra_dip5_y = single(nVRData.dat(ix+116,:)); msg.ra_dip5_z = single(nVRData.dat(ix+117,:));
        msg.ra_dip5_roll = single(nVRData.dat(ix+118,:)); msg.ra_dip5_pitch = single(nVRData.dat(ix+119,:)); msg.ra_dip5_yaw = single(nVRData.dat(ix+120,:));
        msg.ra_tip5_x = single(nVRData.dat(ix+121,:)); msg.ra_tip5_y = single(nVRData.dat(ix+122,:)); msg.ra_tip5_z = single(nVRData.dat(ix+123,:));
        msg.ra_tip5_roll = single(nVRData.dat(ix+124,:)); msg.ra_tip5_pitch = single(nVRData.dat(ix+125,:)); msg.ra_tip5_yaw = single(nVRData.dat(ix+126,:));
        
        SendMessage( nDAQMessage, msg);
    end
    % Add the right hand data if any to the index
    % nVRData.dat(4) will = 0 if there is no game condition data
    ix = ix + nVRData.dat(4);
    
    % check if there is task specific data
    if nVRData.dat(5) > 0
        nDAQMessage  = EnsureNumericMessageType('UE_BOX_AND_BLOCK_DATA');
        msg             = DF.MDF.UE_BOX_AND_BLOCK_DATA;
        msg.t           = single(nTime);
        
        msg.bTargetReachedLeft 	= single(nVRData.dat(ix+1,:));
        msg.bTargetReachedRight 	= single(nVRData.dat(ix+2,:));
        
        SendMessage( nDAQMessage, msg);
    end
end