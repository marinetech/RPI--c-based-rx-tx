function Sig = MainTx(DataBits)
coder.extrinsic('num2str');
%Main FSK transmission

BitNum = length(DataBits);

if length(DataBits) ~= BitNum
    error('Num bits is wrong')
end

Fs = 67500;
Fc1 = 7e3;
Fc2 = 17e3;
BW = Fc2 - Fc1;
M = 8;
Ts = 0.05;
Tref = 0.2;
Tguard = 2e-3;
Amp = 1;
FVec = linspace(Fc1, Fc2, M);
r = 0.3;
Tshort = 1024/Fs;

SymbolNum = ceil(BitNum / log2(M));
Padder = num2str(zeros(1, SymbolNum*log2(M) - length(BitNum)));
DataBits = [DataBits, Padder(1:3:end)];

SymbolVec = [];
for SymbolID = 0: SymbolNum-1
    CurrentBit = DataBits(SymbolID*log2(M)+1: min([(SymbolID+1)*log2(M), length(DataBits)]));
    diff = log2(M) - length(CurrentBit);
    ZeroPadder = num2str(zeros(1,diff));
    CurrentBit = [ZeroPadder(1:3:end), CurrentBit];
    Data = bin2dec(CurrentBit);
    SymbolVec = [SymbolVec, dec2base(Data, M)];
end

t = linspace(0, Ts, round(Ts*Fs));
TxSig = [];
for SymInd = 1: length(SymbolVec)
    CurrentF = FVec(str2num(SymbolVec(SymInd))+1);
    TxSig = [TxSig, Amp * cos(2*pi*CurrentF*t), zeros(1, round(Tguard*Fs))];
end
TxSig = tukeywin(length(TxSig),r).'.*TxSig/std(TxSig);

t = linspace(0, Tref, round(Tref*Fs));
LFMSignal = Amp*chirp(t,Fc1,t(end),Fc2);
LFMSignal = tukeywin(length(LFMSignal),r).'.*LFMSignal/std(LFMSignal);

t = linspace(0, Tshort, round(Tshort*Fs));
ShortLFMSignal = Amp*chirp(t,Fc1,t(end),Fc2);
ShortLFMSignal = tukeywin(length(ShortLFMSignal),r).'.*ShortLFMSignal/std(ShortLFMSignal);

Sig = [ShortLFMSignal, zeros(1, round(Tguard*Fs)), LFMSignal, zeros(1, round(Tguard*Fs)), TxSig];
