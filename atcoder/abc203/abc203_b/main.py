def solve():
    N, K = map(int, input().split())

    ans = 0
    for i in range(N):
        for j in range(K):
            v = str(i+1)+'0'+str(j+1)
            iv = int(v)
            ans += iv

    print(ans)


solve()
