def solve():
    N = int(input())

    S = set()
    for idx in range(1, N*2+2):
        S.add(idx)

    while True:
        # print(S)
        tk = S.pop()
        print(tk)
        ak = int(input())
        if ak == 0:
            exit(0)
        S.remove(ak)


solve()
