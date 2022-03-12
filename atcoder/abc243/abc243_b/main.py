def solve():
    N = int(input())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]

    aaa = 0
    bbb = 0

    for idx in range(N):
        if A[idx] == B[idx]:
            aaa += 1

    da = dict()
    db = dict()
    for idx in range(N):
        da[A[idx]] = idx
        db[B[idx]] = idx

    for ka, va in da.items():
        if ka in db:
            vb = db[ka]
            if va != vb:
                bbb += 1

    print(aaa)
    print(bbb)


solve()
