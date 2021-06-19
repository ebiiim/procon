def solve():
    N = int(input())

    v = int((1.08 * N))

    if v == 206:
        print("so-so")
    elif v > 206:
        print(":(")
    else:
        print("Yay!")


solve()
