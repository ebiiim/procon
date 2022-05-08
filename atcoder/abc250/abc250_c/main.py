def solve():
    N, Q = map(int, input().split())

    X = dict()
    L = -10101010
    R = 10101010
    for idx in range(1, N+1):
        me = idx
        left = idx - 1
        right = idx + 1
        if idx == 1:
            left = L
        if idx == N:
            right = R

        X[idx] = [me, left, right]  # [Position, LeftValue, RightValue]

    for _ in range(Q):
        # print("Before", X)
        q = int(input())
        # print(q)
        myPos, lVal, rVal = X[q]
        if myPos == N:
            q = lVal
            myPos, lVal, rVal = X[q]

        myPos2, lVal2, rVal2 = X[rVal]

        # print("q, rval", q, rVal)
        X[q] = [myPos2, rVal, rVal2]
        X[rVal] = [myPos, lVal, lVal2]

        if lVal != L:
            _a, _b, _c = X[lVal]
            X[lVal] = [_a, _b, rVal]
        if rVal2 != R:
            _a, _b, _c = X[rVal2]
            X[rVal2] = [_a, q, _c]

    nextVal = -1
    for k, v in X.items():
        if v[0] == 1:
            nextVal = k
    ans = str(nextVal) + " "
    while True:
        nextVal = X[nextVal][2]
        if nextVal == R:
            break
        ans += str(nextVal) + " "
    print(ans[:-1])


solve()
