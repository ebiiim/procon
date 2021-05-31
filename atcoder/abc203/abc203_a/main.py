def solve():
    A = [int(i) for i in input().split()]
    B = set(A)
    if len(B) == 3:
        print(0)
        exit(0)

    if len(B) == 1:
        print(A[0])
        exit(0)

    if A[0] == A[1]:
        print(A[2])
    elif A[1] == A[2]:
        print(A[0])
    elif A[0] == A[2]:
        print(A[1])


solve()
