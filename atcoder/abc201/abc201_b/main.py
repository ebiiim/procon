
def solve():
    N = int(input())
    a = list()
    for x in range(N):
        X, Y = input().split()
        Y = int(Y)
        a.append((X, Y))

    aa = sorted(a, key=lambda tup: tup[1])

    print(aa[-2][0])


solve()
