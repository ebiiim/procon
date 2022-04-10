from collections import deque


def solve():
    N = int(input())

    q = deque()
    for idx in range(N):
        A = [int(i) for i in input().split()]
        if A[0] == 1:
            pass
            val = A[1]
            balls = A[2]
            q.append([val, balls])
        else:
            ans = 0
            popnum = A[1]
            while True:
                l = q.popleft()
                minpop = min(popnum, l[1])
                ans += minpop * l[0]
                l[1] -= minpop
                if l[1] != 0:
                    q.appendleft(l)
                popnum -= minpop
                if popnum == 0:
                    break
            print(ans)
            pass


solve()
