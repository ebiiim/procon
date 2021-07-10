def solve():
    X, Y = map(int, input().split())

    if Y-X < 0:
        print(0)
    else:
        print(Y-X+1)


solve()
