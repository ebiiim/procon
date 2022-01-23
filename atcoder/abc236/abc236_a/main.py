def solve():
    N = input()
    X, Y = map(int, input().split())

    a = ""

    for i in range(len(N)):
        if i == X-1:
            a += N[Y-1]
        elif i == Y-1:
            a += N[X-1]
        else:
            a += N[i]

    print(a)


solve()
