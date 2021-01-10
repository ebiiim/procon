# WA
# 問題は有向グラフで、↓のDFSは無向グラフ...
from itertools import combinations


def main():
    N, M = input().split()
    N, M = int(N), int(M)
    A = [int(i) for i in input().split()]

    G = [set() for i in range(N)]
    for i in range(M):
        X, Y = input().split()
        X, Y = int(X)-1, int(Y)-1
        G[X].add(Y)
        G[Y].add(X)
    GG = [list(s) for s in G]
    # print(GG)

    # ↓のクロージャと共有するqueue
    q = list()
    # https://blog.logicky.com/2017/01/31/python3-%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%EF%BC%88%E3%82%B0%E3%83%A9%E3%83%95%EF%BC%89/

    def search(goal, path) -> bool:
        n = path[-1]
        if n == goal:
            print(path)
            q.append(True)
        else:
            for x in GG[n]:
                if x not in path:
                    path.append(x)
                    search(goal, path)
                    path.pop()

    cs = list(combinations(range(0, N), 2))
    max = -pow(10, 10)
    for c in cs:
        print(c)
        print("price ", A[c[0]], A[c[1]])
        price = A[c[1]] - A[c[0]]
        # search(c[1], [c[0]])
        # print(q.pop())
        search(c[1], [c[0]])
        if not q.pop():  # goal, start
            print("NG")
            continue
        print(price)
        if price > max:
            max = price
    print(max)


if __name__ == '__main__':
    main()
