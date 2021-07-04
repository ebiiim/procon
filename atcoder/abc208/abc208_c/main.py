def solve():
    N, K = map(int, input().split())
    A = [int(i) for i in input().split()]
    B = [[A[i], i, False] for i in range(len(A))]

    base = K//N
    nokori = K % N

    # print(nokori, base)
    # print(B)

    B.sort(key=lambda x: x[0])

    # print(B)

    for i in range(nokori):
        # print(B[i])
        B[i][2] = True
        # print(B[i])

    B.sort(key=lambda x: x[1])

    # print(B)

    for b in B:
        if b[2] == False:
            print(base)
        else:
            print(base+1)


solve()
