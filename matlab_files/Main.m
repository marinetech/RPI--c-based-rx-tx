%Main
Fs = 67500;
Tnoise = 1;
Data = '101010101010101010101010101';
Sig = MainTx(Data);

ErrNum = [];
for NoiseStd = 0: 1: 10
    NoiseStd
    %channel
    RxSig = [zeros(1, Tnoise*Fs), Sig + randn(1, length(Sig))*NoiseStd, zeros(1, Tnoise*Fs)];
    
    DataBitsVec = MainRx_RT(RxSig, length(Data));
    if any(DataBitsVec)
        ErrNum = [ErrNum, sum(DataBitsVec ~= Data)];
    else
        ErrNum = [ErrNum, -1];
    end
end

figure;plot(0: 1: 100, ErrNum);
