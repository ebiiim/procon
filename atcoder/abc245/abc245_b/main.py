def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    d = dict()

    for a in A:
        d[a] = True

    for n in range(0, 2020):
        if n not in d:
            print(n)
            return


solve()
