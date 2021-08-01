def solve():
    M, N = map(int, input().split())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]

    A.sort()
    B.sort()

    # print(A)
    # print(B)

    a = A.pop()
    b = B.pop()
    curmin = abs(a-b)

    popA = True
    if a < b:
        popA = False

    while True:
        if len(A) == 0 and len(B) == 0:
            print(curmin)
            exit(0)

        # print("------")
        # print(A)
        # print(B)

        if popA:
            a = A.pop()
        else:
            b = B.pop()
        nextmin = abs(a-b)
        if curmin > nextmin:
            curmin = nextmin
        if a < b:
            popA = False
        else:
            popA = True
        if len(A) == 0:
            popA = False
        if len(B) == 0:
            popA = True


solve()
