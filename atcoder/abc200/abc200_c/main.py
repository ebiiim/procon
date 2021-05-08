def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    cnt = 0

    m = [0 for i in range(210)]

    for v in A:
        # print("try", v % 200)
        cnt += m[v % 200]
        m[v % 200] += 1

    print(cnt)


solve()
