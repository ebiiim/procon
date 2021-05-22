def solve():
    N = input()
    N = reversed(N)
    a = ""
    for n in N:
        if n == "6":
            n = "9"
        elif n == "9":
            n = "6"
        a += n
    print(a)


solve()
