from re import S


def solve():
    X, K = map(int, input().split())
    S = []
    for _ in range(X):
        S.append(input())

    ans = 0

    from itertools import product
    items = S
    for bits in product([0, 1], repeat=len(items)):
        comb = [x for x, bit in zip(items, bits) if bit == 1]
        # print("---")
        # print(comb)
        d = dict()
        for s in comb:
            for c in s:
                if c not in d:
                    d[c] = 1
                else:
                    d[c] += 1
            cnt = 0
            # print(d)
            for k, v in d.items():
                if v == K:
                    cnt += 1
            ans = max(ans, cnt)

    print(ans)


solve()
