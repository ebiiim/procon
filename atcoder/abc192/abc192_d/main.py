

def Base_n_to_10(X, n):
    out = 0
    for i in range(1, len(str(X))+1):
        out += int(X[-i])*(n**(i-1))
    return out


def binary_search_loop(data, target):
    imin = 0
    imax = len(data)-1
    while imin <= imax:
        imid = imin + (imax - imin) // 2
        if target == data[imid]:
            return True
        elif target < data[imid]:
            imax = imid - 1
        else:
            imin = imid + 1
    return False


def solve():
    X = int(input())
    M = int(input())

    start = max([int(c) for c in str(X)])
    # print(start)
    start += 1
    end = 1000000000000000000

    imin = start
    imax = end

    tooLarge = -1
    lastMid = -1

    # 1桁の場合は特別
    if len(str(X)) == 1:
        if X > M:
            print(0)
            exit(0)
        else:
            print(1)
            exit(0)

    while imin <= imax:
        imid = imin + (imax - imin) // 2
        # imid 進数
        # print("imid=", imid)
        x = Base_n_to_10(str(X), imid)
        # print("baseNto10", str(X), imid, x)
        if x == M:
            # print("eq", x)
            tooLarge = 1
            lastmid = imid
            break
        elif x > M:
            # print("too large")
            tooLarge = 0
            lastmid = imid
            imax = imid - 1
        else:
            # print("too small")
            tooLarge = 1
            lastmid = imid
            imin = imid + 1

    ans = lastmid+tooLarge-start
    print(ans)
    # print(Base_n_to_10(str(X), 2))


solve()
