def solve():
    N = int(input())

    mS = -1
    mI = -1
    dup = set()

    for idx in range(N):
        S, T = input().split()
        T = int(T)
        if S in dup:
            continue
        dup.add(S)
        if T > mS:
            mS = T
            mI = idx

    print(mI+1)


solve()
