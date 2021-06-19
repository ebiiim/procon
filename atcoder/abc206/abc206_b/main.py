def solve():
    N = int(input())

    day = 1
    _sum = 0
    while True:
        _sum += day
        day += 1
        if _sum >= N:
            print(day-1)
            exit(0)


solve()
