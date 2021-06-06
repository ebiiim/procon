def solve():
    X, Y = map(int, input().split())

    if X == Y:
        print(X)
        exit(0)

    l = [0, 1, 2]
    l.remove(X)
    l.remove(Y)
    print(l[0])


solve()
