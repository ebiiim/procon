def solve():
    N, K = map(int, input().split())

    for idx in range(K):
        if N % 200 == 0:
            N //= 200
        else:
            N = int(str(N) + "200")

    print(N)


solve()
