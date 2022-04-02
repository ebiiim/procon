def solve():
    X1, Y1 = map(int, input().split())
    X2, Y2 = map(int, input().split())
    X3, Y3 = map(int, input().split())

    X4 = -1
    Y4 = -1

    #print(X1, X2, X3)
    #print(Y1, Y2, Y3)

    if X1 == X2:
        X4 = X3
    if X2 == X3:
        X4 = X1
    if X3 == X1:
        X4 = X2

    if Y1 == Y2:
        Y4 = Y3
    if Y2 == Y3:
        Y4 = Y1
    if Y3 == Y1:
        Y4 = Y2

    print(X4, Y4)


solve()
