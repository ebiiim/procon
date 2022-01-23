import itertools


def solve():
    N = int(input())
    A = [[-1]*16 for i in range(16)]

    for i in range(0, 2*N-1):
        AAA = [int(i) for i in input().split()]
        cnt = 0
        # print(AAA)
        for j in range(i+1, 2*N):
            # print(i, j, AAA[cnt])
            A[i][j] = AAA[cnt]
            cnt += 1

    ans = 0

    maxnum = len(list(itertools.combinations([i for i in range(0, N)], 2)))

    for z in range(0, N):
        for i in range(z+1, 2*N):
            print(z, i)
            for j in range(i+1, 2*N):
                print(i, j)


solve()
