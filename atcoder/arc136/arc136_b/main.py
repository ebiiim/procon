def solve():
    N = int(input())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]

    SA = sorted(A)
    SB = sorted(B)

    if SA != SB:
        print("No")
        exit(0)

    DA = dict()
    DB = dict()

    for idx in range(len(A)):
        vv = "err"
        if idx != len(A) - 1:
            vv = str(A[idx])+"|"+str(A[idx+1])
        else:
            # vv = str(A[idx])+"|"+str(A[0])
            pass
        if vv not in DA:
            DA[vv] = 1
        else:
            DA[vv] += 1

    for idx in range(len(B)):
        vv = "err"
        if idx != len(B) - 1:
            vv = str(B[idx])+"|"+str(B[idx+1])
        else:
            # vv = str(B[idx])+"|"+str(B[0])
            pass
        if vv not in DB:
            DB[vv] = 1
        else:
            DB[vv] += 1

    # print(DA)
    # print(DB)

    for ak, av in DA.items():
        if ak in DB:
            minv = min(av, DB[ak])
            DA[ak] -= minv
            DB[ak] -= minv

    # print(DA)
    # print(DB)

    cntA = 0
    cntB = 0

    for k, v in DA.items():
        cntA += v
    for k, v in DB.items():
        cntB += v

    if abs(cntA - cntB) % 2 != 0:
        print("No")
        exit(0)

    print("Yes")
    exit(0)


solve()
