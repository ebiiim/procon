def solve():
    N = int(input())

    V = []

    for idx in range(N):
        X, Y = map(int, input().split())
        V.append([X, Y])

    S = input()
    SS = [char for char in S]

    for idx in range(N):
        V[idx].append(S[idx])

    # print(V)

    D = dict()

    for v in V:
        x = v[0]
        y = v[1]
        lr = v[2]

        if y not in D:
            D[y] = [-1, 123456789012]  # Lは大きくする, Rは小さくする

        if lr == "L":
            D[y][0] = max(D[y][0], x)
        else:
            D[y][1] = min(D[y][1], x)

    # print(D)

    for k, v in D.items():
        if v[0] >= v[1]:
            print("Yes")
            exit(0)

    print("No")


solve()
