def solve():
    N = int(input())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]

    X = [0 for i in range(101010)]

    for i in range(N):
        x = B[C[i]-1]
        X[x] += 1

    cnt = 0
    for a in A:
        cnt += X[a]
    print(cnt)


solve()
