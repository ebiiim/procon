import math


def solve():
    L, R = map(int, input().split())

    vMax = 0
    for i in range(500):
        for j in range(500):
            l = L+i
            r = R-j
            if l >= r:
                # print("BK")
                break
            # print(l, r)
            if math.gcd(l, r) == 1:
                vMax = max(vMax, abs(l-r))

    print(vMax)


solve()
