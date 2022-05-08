import math


def get_primes(n: int) -> list:
    if n < 2:
        return []

    def find_first_true(l):
        for i, b in enumerate(l):
            if b:
                return i
        return 0
    p = []
    a = [True for i in range(n+1)]
    a[0] = False
    a[1] = False
    x = math.sqrt(n)
    while True:
        v = find_first_true(a)
        if v > x:
            [p.append(i) for i, b in enumerate(a) if b]
            break
        p.append(v)
        i = 1
        while v*i < len(a):
            a[v*i] = False
            i += 1
    return p


def fk(p, q):
    v = p * (q**3)
    # print("p,q,v", p, q, v)
    return v


def solve():
    N = int(input())
    P = get_primes(1000000)

    cnt = 0

    idxL = 0
    idxR = len(P)-1

    while True:
        while True:
            if idxR == idxL:
                break
            if fk(P[idxL], P[idxR]) <= N:
                break
            idxR -= 1
        # print("idx", idxL, idxR)
        if idxR == idxL:
            break
        cnt += idxR - idxL
        idxL += 1

    print(cnt)


solve()
