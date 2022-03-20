def solve():
    S1, S2, S3 = input().split()
    T1, T2, T3 = input().split()

    s = 0

    if S1 != T1:
        s += 1
    if S2 != T2:
        s += 1
    if S3 != T3:
        s += 1

    if s == 0:
        print("Yes")
    if s == 2:
        print("No")
    if s == 3:
        print("Yes")


solve()
