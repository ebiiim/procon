def solve():
    N, X, Y = input().split()
    N, X, Y = int(N), int(X), int(Y)

    max_seppen = 0
    for idx in range(N):
        X2, Y2 = input().split()
        X2, Y2 = int(X2), int(Y2)
        katamuki = (Y2-Y)/(X2-X)
        # print("katamuki", katamuki)
        seppen = Y - (katamuki*X)
        # print("seppen", seppen)
        if seppen > max_seppen:
            max_seppen = seppen

    print(max_seppen)


solve()
