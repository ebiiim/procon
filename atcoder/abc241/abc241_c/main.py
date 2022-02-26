def solve():
    N = int(input())
    # X, Y, Z = map(int, input().split())
    # A = [int(i) for i in input().split()]

    S0 = []
    for n in range(N):
        s = [char for char in input()]
        S0.append(s)

    import numpy as np
    nS0 = np.array(S0)
    nS1 = np.rot90(nS0)
    nS2 = np.rot90(nS1)
    nS3 = np.rot90(nS2)

    S1 = nS1.tolist()
    S2 = nS2.tolist()
    S3 = nS3.tolist()

    # print("S0")
    # for ss in S0:
    #     print(''.join(ss))

    # print("S1")
    # for ss in S1:
    #     print(''.join(ss))

    # print("S2")
    # for ss in S2:
    #     print(''.join(ss))

    # print("S3")
    # for ss in S3:
    #     print(''.join(ss))

    # exit(0)

    isOk = False

    SX = []
    for i in range(0, N):
        arr = []
        for j in range(0, i+1):
            # print("i,j", i-j, j)
            arr.append(S0[i-j][j])
        # print("---")
        SX.append(arr)
    for i in range(0, N):
        arr = []
        for j in range(0, i+1):
            # print("i,j", i-j, j)
            arr.append(S2[i-j][j])
        # print("---")
        SX.append(arr)

    SX2 = []
    for i in range(0, N):
        arr = []
        for j in range(0, i+1):
            # print("i,j", i-j, j)
            arr.append(S1[i-j][j])
        # print("---")
        SX2.append(arr)
    for i in range(0, N):
        arr = []
        for j in range(0, i+1):
            # print("i,j", i-j, j)
            arr.append(S3[i-j][j])
        # print("---")
        SX2.append(arr)

    SZ = S0+S1+SX+SX2
    for sz in SZ:
        # print(sz)
        if len(sz) < 6:
            # print("pass")
            continue
        cnt = 0
        for idx in [0, 1, 2, 3, 4, 5]:
            if sz[idx] == "#":
                cnt += 1
        if cnt >= 4:
            print("Yes")
            exit(0)

        for idx in range(6, len(sz)):
            if sz[idx-6] == "#":
                cnt -= 1
            if sz[idx] == "#":
                cnt += 1
            if cnt >= 4:
                print("Yes")
                exit(0)

    print("No")
    exit(0)


solve()
