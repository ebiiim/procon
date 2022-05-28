def solve():
    A = [int(i) for i in input().split()]

    b = A[1]

    A.sort()

    if A[1] == b:
        print("Yes")
    else:
        print("No")

solve()
