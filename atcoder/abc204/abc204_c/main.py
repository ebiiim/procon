

def solve():
    from collections import deque

    n, m = map(int, input().split())

    graph = [[] for _ in range(n+1)]

    for i in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)

    vvv = 0

    for iii in range(n+1):
        dist = [-1] * (n+1)
        dist[0] = 0
        dist[iii] = 0

        d = deque()
        d.append(iii)

        while d:
            v = d.popleft()
            for i in graph[v]:
                if dist[i] != -1:
                    continue
                dist[i] = dist[v] + 1
                d.append(i)
        x = n-(dist[1:].count(-1))
        # print(iii, x)
        vvv += x

    print(vvv)


solve()
