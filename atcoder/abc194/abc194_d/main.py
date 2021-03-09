def solve():
    N = int(input())

    v = 0

    B = [n for n in range(1, N)]
    for x in B:
        v += 1/x

    print(N*v)


solve()
