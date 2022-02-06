def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    deg = 0
    X = []
    for a in A:
        deg = (deg+a)%360
        X.append(deg)
    
    # print(X)
    X = sorted(X)
    # print(X)

    ans = X[0]
    for idx in range(1,N):
        ans = max(X[idx] - X[idx-1], ans)

    ans = max(360-X[-1],ans)
    print(ans)

solve()
