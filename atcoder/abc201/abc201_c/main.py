def solve():
    N = input()

    aa = list()

    for i1 in range(10):
        for i2 in range(10):
            for i3 in range(10):
                for i4 in range(10):
                    aa.append(str(i1)+str(i2)+str(i3)+str(i4))
    # print(len(aa))

    cnt = 0
    for a in aa:
        # check
        ok = True
        for idx, val in enumerate(N):
            # val: o?x
            if (val == "o") and not (str(idx) in a):
                ok = False
            if (val == "x") and (str(idx) in a):
                ok = False
        if ok:
            cnt += 1

    print(cnt)


solve()
