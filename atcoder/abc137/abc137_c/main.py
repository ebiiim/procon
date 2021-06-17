def nCk(n, r):
    if n - r < r:
        r = n - r
    if r == 0:
        return 1
    if r == 1:
        return n

    numerator = [n - r + k + 1 for k in range(r)]
    denominator = [k + 1 for k in range(r)]

    for p in range(2, r+1):
        pivot = denominator[p - 1]
        if pivot > 1:
            offset = (n - r) % p
            for k in range(p-1, r, p):
                numerator[k - offset] /= pivot
                denominator[k] /= pivot

    result = 1
    for k in range(r):
        if numerator[k] > 1:
            result *= int(numerator[k])

    return result


def solve():
    N = int(input())
    A = ["".join(sorted(input())) for _ in range(N)]
    D = dict()

    for a in A:
        if a not in D:
            D[a] = 1
        else:
            D[a] += 1

    ans = 0
    for k, v in D.items():
        # print(k, v)
        if v == 1:
            continue
        ans += nCk(v, 2)

    print(ans)


solve()
