def solve():
    N, X = map(int, input().split())
    S = input()
    SS = [char for char in S]

    stk = []

    for s in SS:
        if s == "U":
            if len(stk) > 0 and stk[-1] != "U":
                stk.pop()
            else:
                stk.append("U")
        elif s == "L":
            stk.append("L")
            pass
        elif s == "R":
            stk.append("R")
            pass
        else:
            exit(666)

    # print("S1", S)
    # print("S2", ''.join(stk))

    for s in stk:
        if s == "U":
            X = X >> 1
            pass
        elif s == "L":
            X = X << 1
            pass
        elif s == "R":
            X = (X << 1) + 1
            pass
        else:
            exit(666)

    print(X)


solve()
