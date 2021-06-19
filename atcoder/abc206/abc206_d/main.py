def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    if N % 2 == 0:
        L = A[0:N//2]
        R = list(reversed(A[N//2:]))
    else:
        L = A[0:N//2+1]
        R = list(reversed(A[N//2:]))

    assert len(L) == len(R)

    cnt = 0
    # s = set()
    t = set()
    for idx in range(len(L)):
        if L[idx] != R[idx]:
            if L[idx] not in t or R[idx] not in t:
                cnt += 1
                # ss = str(min(L[idx], R[idx]))+"|"+str(max(L[idx], R[idx]))
                # s.add(ss)
            t.add(L[idx])
            t.add(R[idx])

    print(cnt)
    # ans1 = len(s)
    # # ans2 = len(t)
    # if ans1 == -1:
    #     ans1 = 0
    # print(ans1)
    # print(min(ans1, ans2))
    # for sss in s:
    #     print(sss)

    # print(L)
    # print(R)
    # print(len(s))


solve()
