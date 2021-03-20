
L = list()


def solve():

    N = int(input())

    # create list
    for i in range(1, 10):
        L.append(int(str(i) + str(i)))
    for i in range(10, 100):
        L.append(int(str(i) + str(i)))
    for i in range(100, 1000):
        L.append(int(str(i) + str(i)))
    for i in range(1000, 10000):
        L.append(int(str(i) + str(i)))
    for i in range(10000, 100000):
        L.append(int(str(i) + str(i)))
    for i in range(100000, 1000000):
        L.append(int(str(i) + str(i)))

    cnt = 0
    for v in L:
        if v <= N:
            cnt += 1

    print(cnt)


solve()
