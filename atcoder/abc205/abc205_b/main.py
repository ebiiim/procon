def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    A.sort()
    B = [i for i in range(1, N+1)]

    # print(A)
    # print(B)
    # assert len(A) == len(B)

    for i in range(len(A)):
        if A[i] != B[i]:
            print("No")
            exit(0)
    print("Yes")


solve()
