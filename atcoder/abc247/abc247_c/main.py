def solve():
    N = int(input())

    S = [[], []]
    S[0] = [-1]
    S[1] = [1]
    for idx in range(2, 17):

        S.append(S[idx-1] + [idx] + S[idx - 1])

    ss = S[N]
    for idx in range(len(ss)):
        ss[idx] = str(ss[idx])
    print(" ".join(ss))


solve()
