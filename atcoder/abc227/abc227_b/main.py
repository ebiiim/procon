def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    poss = set()
    for a in range(1, 1000):
        for b in range(1, 1000):
            poss.add(4*a*b+3*a+3*b)

    cnt = 0
    for a in A:
        if a not in poss:
            cnt += 1

    print(cnt)


solve()
