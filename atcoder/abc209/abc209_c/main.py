MOD = 1000000007


def solve():
    N = int(input())
    A = [int(i) for i in input().split()]
    A = sorted(A)

    v = 1
    cnt = 0
    for a in A:
        aa = a-cnt
        if aa <= 0:
            aa = 0
        cnt += 1
        v *= aa
        v %= MOD
        # print(aa)

    # print(v)
    print(v)


solve()
