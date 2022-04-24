def solve():
    A, B, C, D, E, F, X = map(int, input().split())

    distn = [[0, 0]]

    tWC = 0
    tSC = -1

    aWC = 0
    aSC = -1

    tD = 0
    aD = 0

    for idx in range(1, 110):
        if tSC == -1:  # tkhs walking
            tD += B
            tWC += 1
            if tWC == A:
                tWC = -1
                tSC = 0
        else:
            tSC += 1
            if tSC == C:
                tSC = -1
                tWC = 0

        if aSC == -1:  # aoki walking
            aD += E
            aWC += 1
            if aWC == D:
                aWC = -1
                aSC = 0
        else:
            aSC += 1
            if aSC == F:
                aSC = -1
                aWC = 0

        status = [tD, aD]
        # print(idx, status)
        distn.append(status)

    val = distn[X]
    # print(X, val)
    if val[0] == val[1]:
        print("Draw")
    elif val[0] > val[1]:
        print("Takahashi")
    else:
        print("Aoki")


solve()
