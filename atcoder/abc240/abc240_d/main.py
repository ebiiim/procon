def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    X = []

    sum = 0
    for a in A:
        X.append([a, 1])
        # print("Add", X)
        sum += 1

        while True:
            if len(X) == 0:
                # print("BK len=0")
                break

            while len(X) > 1:
                if X[-1][0] == X[-2][0]:
                    X[-2][1] += X[-1][1]
                    X.pop()
                    # print("Rdc", X)
                else:
                    # print("BK1")
                    break

            if X[-1][0] == X[-1][1]:
                sum -= X[-1][1]
                X.pop()
                # print("POP1")
            else:
                # print("BK2")
                break

        # print(X)
        print(sum)
        # print(len(X))


solve()
