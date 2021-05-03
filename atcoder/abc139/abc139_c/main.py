def solve():
    N = int(input())
    H = [int(i) for i in input().split()]

    max_idx = -1
    max_dist = 0
    moving = False
    now_dist = 0

    for offset in range(1, N):
        check = H[N-1-offset+1]
        peek = H[N-1-offset]

        # print(peek, check, moving, now_dist)
        if peek >= check:
            if not moving:
                moving = True
                now_dist = 1
            else:
                now_dist += 1
        else:
            if moving:
                moving = False
                if now_dist > max_dist:
                    max_idx = N-offset+1  # check's idx
                    max_dist = now_dist

    if moving:
        moving = False
        if now_dist > max_dist:
            max_idx = N-offset+1  # check's idx
            max_dist = now_dist

    # print(max_idx)
    print(max_dist)


solve()
