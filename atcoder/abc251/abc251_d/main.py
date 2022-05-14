import itertools


def solve():
    W = int(input())

    A = []
    A += [i for i in range(1, 100, 1)]
    A += [i for i in range(100, 10000, 100)]
    A += [i for i in range(10000, 1000000, 10000)]

    test = False

    if test:
        W = 10**6
        l1 = list(itertools.combinations(A, 1))
        l2 = list(itertools.combinations(A, 2))
        l3 = list(itertools.combinations(A, 3))
        s = set()
        for e in l1+l2+l3:
            v = sum(e)
            if v <= W:
                s.add(v)
        print("len(A)", len(A))
        print("len(s)", len(s))
        exit(1)

    print(len(A))
    print(" ".join(map(str, A)))


solve()
