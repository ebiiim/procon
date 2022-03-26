def solve():
    N, X, Y = map(int, input().split())

    ans = [0 for i in range(N)]
    ans[0] = X
    ans[1] = Y
    for i in range(2,N):
        ans[i] = (ans[i-1] + ans[i-2]) % 100

    print(ans[N-1])

solve()
