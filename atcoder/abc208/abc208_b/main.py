def solve():
    P = int(input())

    c1 = 1
    c2 = c1*2
    c3 = c2*3
    c4 = c3*4
    c5 = c4*5
    c6 = c5*6
    c7 = c6*7
    c8 = c7*8
    c9 = c8*9
    c10 = c9*10

    n1 = 0
    n2 = 0
    n3 = 0
    n4 = 0
    n5 = 0
    n6 = 0
    n7 = 0
    n8 = 0
    n9 = 0
    n10 = 0

    cnt = 0
    while P != 0:
        if P >= c10 and n10 < 100:
            P -= c10
            n10 -= 1
            cnt += 1
        elif P >= c9 and n9 < 100:
            P -= c9
            n9 -= 1
            cnt += 1
        elif P >= c8 and n8 < 100:
            P -= c8
            n8 -= 1
            cnt += 1
        elif P >= c7 and n7 < 100:
            P -= c7
            n7 -= 1
            cnt += 1
        elif P >= c6 and n6 < 100:
            P -= c6
            n6 -= 1
            cnt += 1
        elif P >= c5 and n5 < 100:
            P -= c5
            n5 -= 1
            cnt += 1
        elif P >= c4 and n4 < 100:
            P -= c4
            n4 -= 1
            cnt += 1
        elif P >= c3 and n3 < 100:
            P -= c3
            n3 -= 1
            cnt += 1
        elif P >= c2 and n2 < 100:
            P -= c2
            n2 -= 1
            cnt += 1
        elif P >= c1 and n1 < 100:
            P -= c1
            n1 -= 1
            cnt += 1

    print(cnt)


solve()
