
def f(a, b):
    return a*a*a + a*a*b + a*b*b + b*b*b


def solve():
    N = int(input())

    ans = 10**18+12345

    i = 1010101
    j = 0

    while i >= 0:
        while True:
            a = f(i, j)
            # print(i, j, a)
            if a < N:
                j += 1
            else:
                break
        ans = min(ans, f(i, j))
        i -= 1

    print(ans)


solve()
