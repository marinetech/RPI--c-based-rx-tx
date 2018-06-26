function DataBitsVec = MainRx(Sig, BitNumVec)
%Main FSK transmission
%BitNumVec=27

DataBitsVec = [];

BitNum = BitNumVec;
Fs = 67500;
%Fs = 250000;
Fc1 = 7e3;
%Fc1 = 48e3;
Fc2 = 17e3;
%Fc2 = 78e3;
BW = Fc2 - Fc1;
M = 8;
SymbolNum = BitNumVec / log2(M);
Ts = 0.05;
Tref = 0.2;
Tguard = 2e-3;
Amp = 1;
PfaTarget = 1e-4;
FVecBB = linspace(Fc1, Fc2, M) - (Fc1+Fc2)/2;
Factor = 2;
r = 0.3;
L = 128;  % BP filter length
% BPF:
B = 1.2*BW;    % BPF band
% BB conversion:
bLPF = fir1(L, B/Fs);
FsBB = Fs / Factor;

t = linspace(0, Tref, round(Tref*Fs));
Ref = Amp*chirp(t,Fc1,Tref,Fc2);

ad1 = tukeywin(length(Ref),r);
ad2 = ad1.';
Ref = tukeywin(length(Ref),r).'.*Ref/std(Ref);
%Ref = tukeywin(length(Ref),r).'.*Ref/std(Ref);
RefBB = ConvertToBBVer0(reshape(Ref,1,length(Ref)), (Fc1+Fc2)/2, Fs, Factor, bLPF);

SigBB = ConvertToBBVer0(reshape(Sig,1,length(Sig)), (Fc1+Fc2)/2, Fs, Factor, bLPF);

TH = CalcTH(Ts*BW, PfaTarget);% Wideband interceptor threshold
MF = abs(NormCorrVer0(SigBB,RefBB, 1, 1));
MF(find(isinf(MF))) = 0;
loc = find(MF > TH);

BitNumVec = sort(BitNumVec);
MaxSymbolNum = ceil(max(BitNumVec) / log2(M));

if any(loc)
    loc = loc(1);
    DataWindow = SigBB(loc + round((Tref+Tguard)*FsBB): end);
    DecSymbolVec = [];
    LLR = [];
    for SymInd = 0: MaxSymbolNum-1
        CurrentSymbol = DataWindow(SymInd*round((Ts+Tguard)*FsBB)+1: min([(SymInd+1)*round((Ts+Tguard)*FsBB), length(DataWindow)]));
        DataF = abs(fftshift(fft(CurrentSymbol)));
        Faxis = linspace(-FsBB/2, FsBB/2, length(DataF));
        [MaxVal, pos] = max(abs(DataF));
        LLR = [LLR, MaxVal];
        FoundF = Faxis(pos);
        diff = abs(FVecBB - FoundF);
        [~, DecSymbol] = min(diff);
        DecSymbolVec = [DecSymbolVec, num2str(DecSymbol-1)];
    end
    MinSymbolNum = ceil(min(BitNumVec) / log2(M));
    Part1 = LLR(1: MinSymbolNum);
    LastSymbol = MinSymbolNum+1;
    for PossibleNumInd = 2: length(BitNumVec)
        CurrentSymbolNum = ceil(BitNumVec(PossibleNumInd) / log2(M));
        CurrentPart = LLR(LastSymbol: CurrentSymbolNum-1);
        if median(Part1) / median(CurrentPart) > 10
            SymbolNum = LastSymbol-1;
            BitNum = BitNumVec(PossibleNumInd-1);
            DecSymbolVec = DecSymbolVec(1: SymbolNum);
            break;
        end
        LastSymbol = CurrentSymbolNum;
        if PossibleNumInd == length(BitNumVec)
            SymbolNum = LastSymbol;
            BitNum = BitNumVec(PossibleNumInd);
            DecSymbolVec = DecSymbolVec(1: SymbolNum);            
        end
    end
    
    DataBitsVec = [];
    for SymInd = 1: SymbolNum
        CurrentSym = DecSymbolVec(SymInd);
        DataDec = base2dec(CurrentSym, M);
        DataBits = dec2bin(DataDec, log2(M));
        DataBitsVec = [DataBitsVec, DataBits];
    end
    PadderNum = SymbolNum*log2(M) - BitNum;
    DataBitsVec(end-PadderNum+1:end) = [];
    
else
    disp('No sync signal found');
end

if 0
    %DataBitsVec = '101001111010001100001110110011011111101101';
    if any(DataBitsVec)
        BitNum = log2(128);
        RxSym = [];
        for ind = 0: length(DataBitsVec)/BitNum - 1
            Sym = bin2dec(DataBitsVec(ind*BitNum+1: (ind+1)*BitNum));
            RxSym = [RxSym,Sym];
        end
        disp(char(RxSym));
    end
end
