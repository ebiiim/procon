def solve():
    H, W = map(int, input().split())

    A = []
    for _ in range(H):
        A.append([int(i) for i in input().split()])

    B = []
    for i in range(W):
        b = []
        for j in range(H):
            b.append(A[j][i])
        B.append(b)

    # print(B)

    for b in B:
        bb = [str(bbb) for bbb in b]
        print(' '.join(bb))


solve()
