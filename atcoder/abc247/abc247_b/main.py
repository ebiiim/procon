def solve():
    N = int(input())

    A = []
    # Ds = dict()
    # Dt = dict()
    D = dict()

    for _ in range(N):
        s, t = input().split()
        if s not in D:
            D[s] = 1
        else:
            D[s] += 1
        if t not in D:
            D[t] = 1
        else:
            D[t] += 1
        if s != t:
            A.append([s, t])

    for idx, a in enumerate(A):
        s = a[0]
        t = a[1]
        if D[s] > 1:
            A[idx][0] = "_"
        if D[t] > 1:
            A[idx][1] = "_"

    # print(D)
    # print(A)

    ans = "Yes"
    for a in A:
        if a[0] == "_" and a[1] == "_":
            ans = "No"

    print(ans)


solve()
