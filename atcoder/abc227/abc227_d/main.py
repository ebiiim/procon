import heapq


def solve():
    N, K = map(int, input().split())
    A = [int(i) for i in input().split()]

    A.sort()
    A.reverse()

    h = [0 for i in range(K)]

    for a in A:
        minval = heapq.heappop(h)
        minval += a
        heapq.heappush(h, minval)

    print(min(h))


solve()
