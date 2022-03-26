def solve():
    A, B, C, D = map(int, input().split())

    X1 = "Takahashi"
    X2 = "Aoki"

    if A < C:
        print(X1)
    if A > C:
        print(X2)
    if A == C:
        if B < D:
            print(X1)
        if B > D:
            print(X2)
        if B == D:
            print(X1)


solve()
