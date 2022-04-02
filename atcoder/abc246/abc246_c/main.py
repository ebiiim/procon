def solve():
    N, K, X = map(int, input().split())
    A = [int(i) for i in input().split()]

    B = []
    canUse = 0

    for a in A:
        # print("a//X", a//X)
        # print("a%X", a%X)
        B.append((a % X))
        canUse += a // X

    # B.sort()
    # B.reverse()

    # print("B", B)
    # print("canUse", canUse)

    nokori = K - canUse

    # print("nokori", nokori)

    if nokori < 0:
        # print("c1")
        print(sum(B) - (nokori*X))

    if nokori >= 0:
        # print("c2")
        B.sort()
        B.reverse()
        # print(B)
        print(sum(B[min(nokori, len(B)):]))


solve()
