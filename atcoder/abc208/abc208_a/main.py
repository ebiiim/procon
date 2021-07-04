def solve():
    A, B = map(int, input().split())

    if A > B or A*6 < B:
        print("No")
    else:
        print("Yes")


solve()
