def wa(n):
    return int(n*(n+1)/2)


def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    D = dict()
    for a in A:
        if a not in D:
            D[a] = 1
        else:
            D[a] += 1

    ans = wa(N-1)

    for k, v in D.items():
        ans -= wa(v-1)
        # print(k, v)

    print(ans)


solve()
