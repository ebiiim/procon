def solve():
    N, M = input().split()
    N = int(N)
    M = int(M)

    V = [0 for i in range(N)]

    x = 1
    for i in range(M):
        # check edges
        A, B = input().split()
        A = int(A) - 1
        B = int(B) - 1

        # if V[A] == 0 and V[B] == 0:
        #     x *= 3
        # elif min(V[A], V[B]) == 0:
        #     x *= 2
        # elif min(V[A], V[B]) == 1:
        #     x *= 1
        # elif min(V[A], V[B]) == 2:
        #     x *= 0

        if V[A] == 0 and V[B] == 0:
            x *= 6
        elif min(V[A], V[B]) == 0:
            x *= 2
        elif min(V[A], V[B]) == 1:
            x //= 2
        elif min(V[A], V[B]) == 2:
            x *= 0

        V[A] += 1
        V[B] += 1

    pow3 = V.count(0)

    x *= pow(3, pow3)

    print(x)


solve()
