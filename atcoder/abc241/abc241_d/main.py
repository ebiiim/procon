import bisect


def solve():
    QN = int(input())

    d = dict()
    dk = list(d.keys())

    for qid in range(QN):
        qqq = [int(i) for i in input().split()]
        q = qqq[0]
        x = qqq[1]
        k = -1
        if q != 1:
            k = qqq[2]

        if q == 1:
            if x not in d:
                d[x] = 1
            else:
                d[x] += 1
            dk = list(d.keys())
            # print("dd", d)
            # print("dk", dk)

        if q == 2:
            print("2|", bisect.bisect_left(dk, x))
            # print(d[dk[bisect.bisect_left(dk, x)]])
            pass

        if q == 3:
            print("3|", bisect.bisect_right(dk, x), "->", dk[bisect.bisect_right(dk, x)])
            # print(d[dk[bisect.bisect_right(dk, x)]])
            pass

        # print(qid, hq)


solve()
