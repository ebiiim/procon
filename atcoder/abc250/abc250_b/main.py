def solve():
    N, A, B = map(int, input().split())

    X = [["."]*(N*B) for i in range(N*A)]

    for i in range(0, A*N):
        for j in range(0, B*N):
            # print(i, j, (j//B), (i//A))
            if (j//B) % 2 != (i//A) % 2:
                X[i][j] = "#"

    # print(X)

    for x in X:
        print("".join(x))


solve()
