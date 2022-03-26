def solve():
    N = int(input())

    ans = [0] * 31  # 1 <= N <= 30

    ans[0] = 0
    ans[1] = 1
    ans[2] = 2
    ans[3] = 4

    for i in range(4, 31):
        ans[i] = ans[i-1]+ans[i-2]+ans[i-3]

    print(ans[N])


solve()
