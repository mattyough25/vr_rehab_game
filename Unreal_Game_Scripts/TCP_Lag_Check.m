%%
tMatlab =  convertCharsToStrings(datestr(now, 'MM:SS:FFF'))

for i = 1:1000
    
    tMatlab(i) =  convertCharsToStrings(datestr(now, 'SS:FFF'));
    
    try
        write(TCP_server,tMatlab(i),"string")
    catch
        disp('Data not sent')
    end
    while TCP_server.NumBytesAvailable == 0
       % disp('No Data to Read')
    end
    tUnreal(i) = read(TCP_server,TCP_server.NumBytesAvailable,"string");
    
end


for iString = 1:length(tUnreal)
    tTime.tMat_s(iString) = str2double(erase(insertAfter(tMatlab(iString),":","."),":"));
    tTime.tUR_s(iString) = str2double(erase(insertAfter(tUnreal(iString),":","."),":"));
end

tTime.tDiff_ms = (tTime.tUR_s - tTime.tMat_s)*1000;

tPos = tTime.tDiff_ms > 0;
tTime.tDiff_ms(~tPos) = (60 - tTime.tMat_s(~tPos) + tTime.tUR_s(~tPos))*1000;

tTime.tAvgDelay_ms = mean(tTime.tDiff_ms);

save_csv(tTime,'sFile','TCP_Socket_Delay.csv')
    