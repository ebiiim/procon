def solve():
    N, M = map(int, input().split())
    A = [int(i) for i in input().split()]

    ans = [1000000000] * (N)
    ans[0] = 0

    for i in range(1, N):
        for j in range(1, M+1):
            if (i-j) >= 0:
                tmp = ans[i-j] + j * A[i]
                ans[i] = min(tmp, ans[i])

    # print(ans)
    print(ans[N-1])


solve()
