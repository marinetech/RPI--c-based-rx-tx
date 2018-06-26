function [CurrentTailSenderIDMat,CurrentTailSenderIDMatTime] = checkPckTail(N, NodeInd,PckNumTailMat,RxPck)
%CHECKPCKTAIL Summary of this function goes here
%   Detailed explanation goes here
%% check tail
    CurrentTailSenderIDMat = zeros(N, size(PckNumTailMat, 2));
    CurrentTailSenderIDMatTime = inf(N, size(PckNumTailMat, 2));
    for PossibleSenderInd = 1: N
        if PossibleSenderInd ~= NodeInd
            for PckNumInd = 1: size(PckNumTailMat, 2)
                PossibleTail = PckNumTailMat(PossibleSenderInd, PckNumInd);
                LocTail1 = find(RxPck == PossibleTail);
                LocTail2 = find(RxPck == PossibleTail+1);
                LocTail3 = find(RxPck == PossibleTail+2);

                NumFound = 0;
                TimeFound = 0;
                for ind1 = 1: length(LocTail1)
                    Loc2 = find(LocTail2 == LocTail1(ind1)+1);
                    Loc3 = find(LocTail3 == LocTail1(ind1)+2);

                    if any(Loc2) || any(Loc3)
                        NumFound = any(Loc2) + any(Loc3) + 1;
                        TimeFound = LocTail1(ind1);
                        break;
                    end
                end
                if NumFound == 0
                    for ind2 = 1: length(LocTail2)
                        Loc3 = find(LocTail3 == LocTail2(ind2)+1);
                        if any(Loc3)
                            NumFound = 2;
                            TimeFound = LocTail2(ind2);
                            break;
                        end
                    end
                end

                if NumFound ~= 0
                    %found valid PckNum for header
                    CurrentTailSenderIDMat(PossibleSenderInd, PckNumInd) = NumFound;
                    CurrentTailSenderIDMatTime(PossibleSenderInd, PckNumInd) = TimeFound;
                end
            end
        end
    end

end

