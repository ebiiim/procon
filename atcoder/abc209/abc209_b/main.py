def solve():
    N, X = map(int, input().split())
    A = [int(i) for i in input().split()]

    v = sum(A) - N//2

    if X >= v:
        print("Yes")
    else:
        print("No")


solve()
