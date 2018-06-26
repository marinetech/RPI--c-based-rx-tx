function [CurrentHeadSenderIDMat,CurrentHeadSenderIDMatTime] = checkPckHeader(N, NodeInd,PckNumHeadMat,RxPck)
%CHECKPCKHEADER Summary of this function goes here
%   Detailed explanation goes here


%% check head
    CurrentHeadSenderIDMat = zeros(N, size(PckNumHeadMat, 2));
    CurrentHeadSenderIDMatTime = inf(N, size(PckNumHeadMat, 2));
    for PossibleSenderInd = 1: N
        if PossibleSenderInd ~= NodeInd
            for PckNumInd = 1: size(PckNumHeadMat, 2)
                PossibleHead = PckNumHeadMat(PossibleSenderInd, PckNumInd);
                LocHead1 = find(RxPck == PossibleHead);
                LocHead2 = find(RxPck == PossibleHead+1);
                LocHead3 = find(RxPck == PossibleHead+2);

                NumFound = 0;
                TimeFound = 0;
                for ind1 = 1: length(LocHead1)
                    Loc2 = find(LocHead2 == LocHead1(ind1)+1);
                    Loc3 = find(LocHead3 == LocHead1(ind1)+2);

                    if any(Loc2) || any(Loc3)
                        NumFound = any(Loc2) + any(Loc3) + 1;
                        TimeFound = LocHead1(ind1);
                        break;
                    end
                end
                if NumFound == 0
                    for ind2 = 1: length(LocHead2)
                        Loc3 = find(LocHead3 == LocHead2(ind2)+1);
                        if any(Loc3)
                            NumFound = 2;
                            TimeFound = LocHead2(ind2);
                            break;
                        end
                    end
                end

                if NumFound ~= 0
                    %found valid PckNum for header
                    CurrentHeadSenderIDMat(PossibleSenderInd, PckNumInd) = NumFound;
                    CurrentHeadSenderIDMatTime(PossibleSenderInd, PckNumInd) = TimeFound;
                end
            end
        end
    end

end

