def solve():
    N = int(input())

    for _ in range(0, N):
        A, S = map(int, input().split())
        # print(A, S)

        AA = bin(A)[2:]
        # print(bin(A), AA)

        AA = reversed(AA)

        SUM = 0
        for idx, v in enumerate(AA):
            if v == "1":
                SUM += 2 * 2**idx

        # print(S, SUM)

        if S-SUM < 0:
            print("No")
        else:
            if SUM//2 & (S-SUM) == 0:
                print("Yes")
            else:
                print("No")


solve()
