import bisect


def solve():
    N, Q = map(int, input().split())
    A = [int(i) for i in input().split()]

    B = list()
    C = dict()

    cnt = 0
    last = 0
    for i in range(N):
        cnt += 1
        if i != N-1 and (A[i+1] == A[i]+1):
            continue
        last = i
        # print(A[i]-last, cnt)
        B.append(A[i]-last)
        C[A[i]-last] = cnt

        # print("last", last)
        # cnt = 1

    for _ in range(Q):
        K = int(input())
        idx = bisect.bisect_right(B, K)
        idx -= 1
        # print(idx)
        if idx == -1:
            # print("FST")
            print(K)
        else:
            print(K+C[B[idx]])


solve()
