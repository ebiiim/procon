def solve():
    # N = int(input())
    N, X = map(int, input().split())
    # A = [int(i) for i in input().split()]

    A = []
    B = []

    for idx in range(N):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b-a)

    # print(X)
    # print(A)
    # print(B)

    MIN = sum(A)
    TODO = X-MIN

    # print("MIN", MIN)
    # print("TODO", TODO)

    if TODO < 0:
        print("No")
        exit(0)

    dp = [[False]*10010 for i in range(110)]
    dp[0][0] = True

    # assert dp[101][10001] == False

    for i in range(N):
        for j in range(TODO+1):
            dp[i+1][j] |= dp[i][j]
            if (j >= B[i]):
                dp[i+1][j] |= dp[i][j-B[i]]

    if dp[N][TODO]:
        print("Yes")
    else:
        print("No")


solve()
