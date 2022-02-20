def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    S = set()
    for a in A:
        S.add(a)

    # print(S)
    print(len(S))


solve()
