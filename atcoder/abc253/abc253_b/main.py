def solve():
    H, W = map(int, input().split())

    S = []

    for _ in range(H):
        S.append([0 if c == "-" else 1 for c in input()])

    pos11 = -1
    pos12 = -1
    pos21 = -1
    pos22 = -1
    cnt = 0
    for i, s in enumerate(S):
        for j, c in enumerate(s):
            if c == 1:
                if cnt == 0:
                    pos11 = i
                    pos12 = j
                    cnt += 1
                else:
                    pos21 = i
                    pos22 = j

    print(abs(pos21 - pos11) + abs(pos22 - pos12))


solve()
