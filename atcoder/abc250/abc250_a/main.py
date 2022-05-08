def solve():
    H, W = map(int, input().split())
    R, C = map(int, input().split())

    B = [[0]*11 for i in range(11)]

    for i in range(1, H+1):
        for j in range(1, W+1):
            B[i][j] = 1

    cnt = 0
    cnt += B[R][C+1]
    cnt += B[R][C-1]
    cnt += B[R+1][C]
    cnt += B[R-1][C]

    print(cnt)


solve()
