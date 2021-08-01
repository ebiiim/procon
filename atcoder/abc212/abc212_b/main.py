def solve():
    A = input()
    a1 = int(A[0])
    a2 = int(A[1])
    a3 = int(A[2])
    a4 = int(A[3])

    if a1 == a2 == a3 == a4:
        print("Weak")
        # print("1")
        exit(0)

    if (a1+1) % 10 == a2 and (a2+1) % 10 == a3 and (a3+1) % 10 == a4:
        print("Weak")
        exit(0)

    print("Strong")


solve()
