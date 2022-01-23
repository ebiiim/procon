def solve():
    N, M = map(int, input().split())
    S = [i for i in input().split()]
    T = [i for i in input().split()]

    d = set()
    for t in T:
        d.add(t)

    for s in S:
        if s in d:
            print("Yes")
        else:
            print("No")


solve()
