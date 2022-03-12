def solve():
    V, A, B, C = map(int, input().split())

    while True:
        V -= A
        if V < 0:
            print("F")
            exit(0)

        V -= B
        if V < 0:
            print("M")
            exit(0)

        V -= C
        if V < 0:
            print("T")
            exit(0)


solve()
