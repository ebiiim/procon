import itertools


def solve():
    N, W = map(int, input().split())
    A = [int(i) for i in input().split()]
    l1 = list(itertools.combinations(A, 1))
    l2 = list(itertools.combinations(A, 2))
    l3 = list(itertools.combinations(A, 3))
    s = set()

    for e in l1+l2+l3:
        v = sum(e)
        if v <= W:
            s.add(v)

    print(len(s))


solve()
