def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    s = 0

    for a in A:
        if a <= 10:
            continue
        else:
            s += a-10

    print(s)


solve()
