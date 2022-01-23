def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    ansA = [-1] * N
    cntA = [-1] * N
    ansA[0] = A[0]
    cntA[0] = 1
    if ((A[0] + A[1]) / 2) > A[1]:
        ansA[1] = (A[0] + A[1]) / 2
        cntA[1] = 2
    else:
        ansA[1] = A[1]
        cntA[1] = 1

    # ansM = [-1] * (N-1)
    # ansM[0] = A[0]

    for i in range(2, N):
        print(i)
        print(ansA)
        print(cntA)
        print([ans/cnt for (ans, cnt) in zip(ansA, cntA)])
        a = (ansA[i-2] + A[i]) / cntA[i-2]+1
        b = (ansA[i-1] + A[i]) / cntA[i-1]+1
        if a > b:
            ansA[i] = ansA[i-2] + A[i]
            cntA[i] = cntA[i-2]+1
        else:
            ansA[i] = ansA[i-1] + A[i]
            cntA[i] = cntA[i-1]+1

        print(a, b)
        print(ansA)
        print(cntA)
        print([ans/cnt for (ans, cnt) in zip(ansA, cntA)])

    # print(ansA)


solve()
