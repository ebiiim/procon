def solve():
    N = int(input())

    ans = [0] * (N+1)

    if N == 1:
        print("1")
        exit(0)
    if N == 2:
        print("2")
        exit(0)

    ans[0] = 0
    ans[1] = 1
    ans[2] = 2

    for i in range(3, N+1):
        ans[i] = ans[i-1]+ans[i-2]

    print(ans[N])


solve()
