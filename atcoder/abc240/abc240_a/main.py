def solve():
    A, B = map(int, input().split())

    if abs(B - A) == 1:
        print("Yes")
        exit(0)

    if B == 10 and A == 1:
        print("Yes")
        exit(0)

    print("No")


solve()
