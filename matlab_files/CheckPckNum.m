function [PckType,CurrentPckSym] = checkPckNum(N, NodeInd,PckType,PckNumHeadMat,PckNumTailMat,RxPck)
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

    if (sum(sum(CurrentTailSenderIDMat))) || (sum(sum(CurrentHeadSenderIDMat)))
        %% decide on the sender ID: max number of good occurences for packet number, and fist arrival in vector
        [MArrive_Head, LocHead] = max(CurrentHeadSenderIDMat, [], 2);
        loc = find(MArrive_Head);
        LocHead = LocHead(loc);
        CompareTime = [];
        for ind = 1: length(loc)
            CompareTime = [CompareTime, CurrentHeadSenderIDMatTime(loc(ind), LocHead(ind))];
        end
        [M_Head, SenderIDHead] = min(CompareTime);
        SenderIDHead = loc(SenderIDHead);

        [MArrive_Tail, LocTail] = max(CurrentTailSenderIDMat, [], 2);
        loc = find(MArrive_Tail);
        LocTail = LocTail(loc);
        CompareTime = [];
        for ind = 1: length(loc)
            CompareTime = [CompareTime, CurrentTailSenderIDMatTime(loc(ind), LocTail(ind))];
        end
        [M_Tail, SenderIDTail] = min(CompareTime);
        SenderIDTail = loc(SenderIDTail);


        if M_Head <= M_Tail
            SenderID = SenderIDHead;
            [~, CurrentPckNum] = max(CurrentHeadSenderIDMat(SenderID, :));
            FirstPosInRx = M_Head;

            %look for place in vector
            Val = RxPck(FirstPosInRx);
            diff = PckNumHeadMat(SenderID, CurrentPckNum)-Val;
            %if 0 - this is the first pckID symbol, etc.
            if PckType == 1
                CurrentPckSym = RxPck(FirstPosInRx+diff+3: FirstPosInRx+diff+3+PckLenType1-1);
                CurrentPckLen = PckLenType1;
            else
                CurrentPckSym = RxPck(FirstPosInRx+diff+3: FirstPosInRx+diff+3+PckLenType2-1);
                CurrentPckLen = PckLenType2;
            end

            %find arrival time
            NumSymbolsTillEnd = length(RxPck) - (FirstPosInRx+diff+3+3)+1;
            ArrivalTime = TimeEndRx - NumSymbolsTillEnd*Ts; %in seconds from begining of experiement in DESERT

            %% erase packet ID for future search of interfering packet
            Val = PckNumHeadMat(SenderID, CurrentPckNum);
            pos = FirstPosInRx+diff:FirstPosInRx+diff+NumHead-1;
            RxPck(find(RxPck(pos) == Val)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+1)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+2)+pos(1)-1) = -1;

            Val = PckNumTailMat(SenderID, CurrentPckNum);
            pos = FirstPosInRx+diff+NumHead+CurrentPckLen:FirstPosInRx+diff+NumHead+CurrentPckLen+NumTail-1;
            RxPck(find(RxPck(pos) == Val)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+1)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+2)+pos(1)-1) = -1;

        else
            SenderID = SenderIDTail;
            [~, CurrentPckNum] = max(CurrentTailSenderIDMat(SenderID, :));
            FirstPosInRx = M_Tail;

            %look for place in vector
            Val = RxPck(FirstPosInRx);
            diff = PckNumTailMat(SenderID, CurrentPckNum)-Val;
            %if 0 - this is the first pckID symbol, etc.
            if PckType == 1
                CurrentPckSym = RxPck(FirstPosInRx+diff-1-(PckLenType1-1): FirstPosInRx+diff-1);
                %find arrival time
                NumSymbolsTillEnd = length(RxPck) - (FirstPosInRx+diff-1-(PckLenType1-1)+3)+1;
                CurrentPckLen = PckLenType1;
            else
                CurrentPckSym = RxPck(FirstPosInRx+diff-1-(PckLenType2-1): FirstPosInRx+diff-1);
                %find arrival time
                NumSymbolsTillEnd = length(RxPck) - (FirstPosInRx+diff-1-(PckLenType2-1)+3)+1;
                CurrentPckLen = PckLenType2;
            end

            ArrivalTime = TimeEndRx - NumSymbolsTillEnd*Ts; %in seconds from begining of experiement in DESERT

            %% erase packet ID for future search of interfering packet
            Val = PckNumHeadMat(SenderID, CurrentPckNum);
            pos = FirstPosInRx+diff-CurrentPckLen-NumHead:FirstPosInRx+diff-CurrentPckLen-1;
            RxPck(find(RxPck(pos) == Val)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+1)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+2)+pos(1)-1) = -1;

            Val = PckNumTailMat(SenderID, CurrentPckNum);
            pos = FirstPosInRx+diff:FirstPosInRx+diff+NumTail-1;
            RxPck(find(RxPck(pos) == Val)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+1)+pos(1)-1) = -1;
            RxPck(find(RxPck(pos) == Val+2)+pos(1)-1) = -1;
        end

        %number of valid SourseID found in packet
        NumSourcesFound = max([length(find(MArrive_Head)), length(find(MArrive_Tail))]);

    else
        %found no valid PckInd
        CurrentPckSym = [];
    end
end
    