def solve():
    A, B = map(int, input().split())

    if B == 1:
        print(0)
        return

    c = 1
    now = A

    while True:
        if B <= now:
            break
        now += A-1
        c += 1

    print(c)


solve()
