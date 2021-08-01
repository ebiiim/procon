import heapq


def solve():
    N = int(input())

    hq = []
    nowplus = 0
    for _ in range(N):
        XXX = [int(i) for i in input().split()]
        # print(XXX)
        q1 = XXX[0]
        q2 = -1
        if q1 == 1 or q1 == 2:
            q2 = XXX[1]

        if q1 == 1:
            heapq.heappush(hq, q2-nowplus)

        if q1 == 2:
            nowplus += q2

        if q1 == 3:
            v = heapq.heappop(hq)
            print(v+nowplus)


solve()
