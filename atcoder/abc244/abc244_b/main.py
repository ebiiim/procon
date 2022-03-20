def solve():
    N = int(input())
    S = input()

    x = 0
    y = 0
    d = 1
    for c in S:
        if c == "S":
            if d % 4 == 0:  # north
                y += 1
            elif d % 4 == 1:  # east
                x += 1
            elif d % 4 == 2:  # south
                y -= 1
            elif d % 4 == 3:  # west
                x -= 1
        elif c == "R":
            d += 1
        else:
            exit(100)

    print(x, y)


solve()
