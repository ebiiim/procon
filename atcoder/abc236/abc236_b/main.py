def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    x = [0 for n in range(N)]

    for a in A:
        x[a-1] += 1

    for idx, xx in enumerate(x):
        if xx == 3:
            print(idx+1)


solve()
