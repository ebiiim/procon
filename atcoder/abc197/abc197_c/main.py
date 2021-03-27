from functools import reduce
from operator import xor


def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    minval = 1024*1024*1024+100
    n = N-1

    # bit全探索
    for i in range(2 ** n):
        # 区間をわけなくても良いので、i=0もやる

        # print(bin(i))  # e.g. 000100101
        # ors = []
        xored = 0  # 0をxorしても変わらんので0から開始して良い
        # print("OR:", 0)
        ored = A[0]
        for j in range(n):
            if ((i >> j) & 1):  # 1bitずつシフトして、そのbitを使うかどうか、使わないbitはorして、使うbitはxorする
                # jで切り取るので、A[j]はorしない
                # ここまでのorを格納する
                # ors.append(ored)
                xored = xored ^ ored
                ored = A[j+1]
                # print("---")
                # print("OR:", j+1)
            else:
                # print("OR:", j+1)
                ored = ored | A[j+1]
        # ors.append(ored)
        xored = xored ^ ored
        # xored = reduce(xor, ors) # これやるとギリギリTLEする
        if minval > xored:
            minval = xored
    print(minval)


solve()
