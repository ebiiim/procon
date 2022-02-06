def solve():
    N = int(input())

    if N > 10000:
        print("Yes")
        exit(0)

    if 2**N > N**2:
        print("Yes")
    else:
        print("No")


solve()
