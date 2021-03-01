

def getPoint(ls):
    p = 0
    p += 1 * 10**(ls.count(1))
    p += 2 * 10**(ls.count(2))
    p += 3 * 10**(ls.count(3))
    p += 4 * 10**(ls.count(4))
    p += 5 * 10**(ls.count(5))
    p += 6 * 10**(ls.count(6))
    p += 7 * 10**(ls.count(7))
    p += 8 * 10**(ls.count(8))
    p += 9 * 10**(ls.count(9))
    return p


def solve():
    K = int(input())
    Ts = input()
    As = input()

    Tl = [int(Ts[0]), int(Ts[1]), int(Ts[2]), int(Ts[3])]
    Al = [int(As[0]), int(As[1]), int(As[2]), int(As[3])]

    # print(getPoint(Tl))
    # print(getPoint(Al))

    tt = 0  # takahashi win
    ii = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    for v in ii:
        for z in ii:
            maisuuV = K - Tl.count(v) - Al.count(v)
            maisuuZ = K - Tl.count(z) - Al.count(z)
            if maisuuV == 0 or maisuuZ == 0 or (v == z and maisuuV < 2):
                continue  # カードがないパターン
            tmpT = Tl + [v]
            tmpA = Al + [z]
            # print(f"test {v} {z}")
            # print(f"maisuu {maisuuV} {maisuuZ}")
            # print(f"list {tmpT} {tmpA}")
            # print(f"point {getPoint(tmpT)} {getPoint(tmpA)}")
            if getPoint(tmpT) > getPoint(tmpA):
                if (v == z):
                    tt += maisuuV * (maisuuZ-1)
                else:
                    tt += maisuuV * maisuuZ

    dd = (K * 9 - 8) * (K * 9 - 9)
    print(tt/dd)


solve()
