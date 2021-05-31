# TLE

def b(vals):
    import heapq
    ret = 0
    maxh = []
    minh = []
    vals
    for idx, val in enumerate(vals):
        # Initialize the data-structure and insert/push the 1st streaming value
        if not maxh and not minh:
            heapq.heappush(maxh, -val)
            if idx == len(vals)-1:
                ret = val
        elif maxh:
            # Insert/push the other streaming values
            if val >= -maxh[0]:
                heapq.heappush(minh, val)
            else:
                heapq.heappush(maxh, -val)
            # Calculate the median
            if len(maxh) == len(minh):
                if idx == len(vals)-1:
                    # print("a")
                    ret = -maxh[0]
            elif len(maxh) == len(minh)+1:
                heapq.heappush(minh, -heapq.heappop(maxh))
                if idx == len(vals)-1:
                    # print("b")
                    ret = -maxh[0]
            elif len(minh) == len(maxh)+1:
                if idx == len(vals)-1:
                    # print("c")
                    ret = minh[0]
            elif len(minh) == len(maxh)+2:
                heapq.heappush(maxh, -heapq.heappop(minh))
                if idx == len(vals)-1:
                    # print("d")
                    ret = -maxh[0]
            # elif len(maxh) == len(minh)+2:
            #     heapq.heappush(minh, -heapq.heappop(maxh))
            #     if idx == len(vals)-1:
            #         print(float(-maxh[0]+minh[0])/2)
        # print("maxh", maxh)
        # print("minh", minh)
        # print("---")

    return ret


def solve():
    N, K = map(int, input().split())

    X = list()
    for _ in range(N):
        X.append([int(i) for i in input().split()])

    import heapq
    # maxh = []
    # minh = []

    # for i in range(K):
    #     for j in range(K):
    #         print(X[i][j])
    _min = 11111111111
    for i in range(N-K+1):
        for j in range(N-K+1):
            tmp = []
            for k in range(K):
                for l in range(K):
                    # print(X[i+k][j+l])
                    tmp.append(X[i+k][j+l])
            # print("---")
            minv = b(tmp)
            # print(minv)
            if _min > minv:
                _min = minv
    print(_min)


solve()
