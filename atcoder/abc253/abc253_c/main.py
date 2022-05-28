def solve():
    Q = int(input())

    d = dict()

    vMax = -1
    vMin = 10**10
    needCheck = False

    for idx in range(Q):
        A = [int(i) for i in input().split()]
        t = A[0]

        if t == 1:
            x = A[1]
            if x not in d:
                d[x] = 0
                if x > vMax:
                    vMax = x
                if x < vMin:
                    vMin = x
            d[x] += 1

        elif t == 2:
            x = A[1]
            c = A[2]
            if x not in d:
                continue
            rm = min(c, d[x])
            d[x] -= rm
            if d[x] == 0:
                del d[x]
                needCheck = True
        elif t == 3:
            if needCheck:
                vMax = max(d.keys())
                vMin = min(d.keys())
                needCheck = False
            print(vMax-vMin)
        else:
            exit(100)


solve()
