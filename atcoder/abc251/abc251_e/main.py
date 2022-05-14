import heapq

# https://zenn.dev/tomson784/articles/dijkstra_python
def dijkstra(e, n, s):
    hq = [(0, s)]
    heapq.heapify(hq)
    cost = [float('inf')] * n
    cost[s] = 0
    while hq:
        c, v = heapq.heappop(hq)
        if c > cost[v]:
            continue
        for d, u in e[v]:
            tmp = d + cost[v]
            if tmp < cost[u]:
                cost[u] = tmp
                heapq.heappush(hq, (tmp, u))
    return cost


def solve():
    N = int(input())
    A = [int(i) for i in input().split()]
    M = N

    e = [[] for _ in range(N)]
    for idx in range(N):
        a = idx
        b = (idx+2) % N
        t = A[idx]
        a, b = a, b
        print(idx, a, b, t)
        e[a].append((t, b))
        # e[b].append((t, a))

    print(e)
    dist = dijkstra(e, N, N-1)
    print(dist)
    # ans = float('inf')
    # for i in range(N):
    #     dist = dijkstra(e, N, i)
    #     ans = min(ans, max(dist))
    # print(ans)


def solve1():
    N = int(input())
    A = [int(i) for i in input().split()]
    A.reverse()
    B = [A[-1]] + A[0:-1]
    # print(A, B)

    _m = 10**18
    dp = [_m] * N

    dp[0] = A[0]
    dp[1] = A[0]
    for i in range(2, N):
        dp[i] = min(dp[i-1]+A[i], dp[i-2]+A[i])

    dpX = [_m] * N

    dpX[0] = B[0]
    dpX[1] = B[0]
    for i in range(2, N):
        dpX[i] = min(dpX[i-1]+B[i], dpX[i-2]+B[i])

    print(dp)
    print(dpX)


solve()
