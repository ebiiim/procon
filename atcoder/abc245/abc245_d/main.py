def solve():
    N, M = map(int, input().split())
    A = [int(i) for i in input().split()]
    C = [int(i) for i in input().split()]

    B = []

    A.reverse()
    C.reverse()

    # print("A", A)
    # print("C", C)
    # print("B", B)
    # print("---")

    for i in range(0, M+1):
        b = C[i] // A[0]
        B.append(str(b))
        for j in range(0, N+1):
            # print("C[i+j] -= A[j] * b", A[j], b)
            C[i+j] -= A[j] * b
        # print("A", A)
        # print("C", C)
        # print("B", B)
        # print("---")

    B.reverse()

    print(" ".join(B))


solve()
