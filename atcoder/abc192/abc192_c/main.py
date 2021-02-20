
def f(a: int):
    v1 = [int(c) for c in str(a)]
    v1 = sorted(v1)
    i1 = [str(i) for i in v1]
    ii1 = int(''.join(i1))

    v2 = [int(c) for c in str(a)]
    v2 = sorted(v2)
    v2 = reversed(v2)
    i2 = [str(i) for i in v2]
    ii2 = int(''.join(i2))

    return ii2-ii1


def solve():
    N, K = input().split()
    N, K = int(N), int(K)

    a = N

    for i in range(K):
        a = f(a)

    print(a)


solve()
