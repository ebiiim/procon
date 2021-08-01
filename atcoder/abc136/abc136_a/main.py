def solve():
    A, B, C = map(int, input().split())

    ans = C-(A-B)
    if ans < 0:
        ans = 0
    print(ans)


solve()
