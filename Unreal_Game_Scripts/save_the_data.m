function save_the_data(par, nTime, nVRData)

fwrite(par.fid,[nTime; nVRData.dat(2:end)],'single');