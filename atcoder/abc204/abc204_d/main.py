def solve():
    N = int(input())
    T = [int(i) for i in input().split()]

    T.sort(reverse=True)

    left = 0
    right = 0

    for t in T:
        # print("t=", t)
        if left >= right:
            # print("right", right)
            right += t
        else:
            # print("left", left)
            left += t

    print(max(left, right))


solve()
