def solve():
    S = input()
    ans = ""
    l = 6
    while True:
        for c in S:
            ans += c
            if len(ans) == l:
                print(ans)
                exit(0)


solve()
