def solve():
    N = int(input())

    SUM1 = (N*(N+1))//2

    SUM2 = 0

    t = N
    c = 10
    c2 = 0
    c3 = 0  # 9*c3する
    c4 = 0
    while True:
        # print(t)
        if N >= c:
            t -= c-1-c2
            c2 += c-1-c2
            v = ("9"*c4)
            if v == "":
                v = "0"
            # print(" ", 9*c//10, int(v))
            SUM2 += (9*c//10) * int(v)
            c *= 10
            c4 += 1
        else:
            break
    v = ("9"*c4)
    if v == "":
        v = "0"
    # print("X", t, int(v))
    SUM2 += (t) * int(v)

    print((SUM1-SUM2) % 998244353)


solve()
