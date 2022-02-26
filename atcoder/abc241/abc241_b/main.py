def solve():
    N, M = map(int, input().split())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]

    AA = []
    for a in A:
        AA.append([a, True])

    for idx, b in enumerate(B):
        isOk = False
        for a in AA:
            if a[0] == b and a[1] == True:
                isOk = True
                a[1] = False
                break
        # print(idx, AA)

        if not isOk:
            print("No")
            exit(0)

    print("Yes")
    exit(0)


solve()
