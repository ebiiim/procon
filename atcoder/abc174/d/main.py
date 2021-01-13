from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    _ = int(input())
    # R = 0
    # W = 1
    C = [0 if c == "R" else 1 for c in input()]
    # print(C)

    L = 0
    R = len(C)-1

    count = 0
    while True:
        # print(L,R,C)
        # 次の白まで飛ぶ
        while C[L] == 0:
            if L == len(C)-1:
                print(count)
                exit()
            L += 1
        # 次の赤まで飛ぶ
        while C[R] == 1:
            if R == 0:
                print(count)
                exit()
            R -= 1
        # 真ん中まで見たなら終わり
        if R-L < 1:
            print(count)
            exit()

        # 入れ替え
        C[L] = 0
        C[R] = 1
        L += 1
        R -= 1
        count += 1
        # print("!!!")
        # 入れ替え後、終わり？
        if L == len(C)-1:
            print(count)
            exit()
        if R == 0:
            print(count)
            exit()
