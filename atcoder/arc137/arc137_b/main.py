# https://cocoinit23.com/maximum-subarray-kadanes-algorithm/

def maxSubArray(nums) -> int:
    best = -1e9
    cur = 0

    for i in range(len(nums)):
        cur = max(nums[i], nums[i] + cur)
        best = max(best, cur)

    return best


def minSubArray(nums) -> int:
    best = +1e9
    cur = 0

    for i in range(len(nums)):
        cur = min(nums[i], nums[i] + cur)
        best = min(best, cur)

    return best


def solve():
    N = int(input())
    A = [int(i) for i in input().split()]

    B = []

    tCur = 0
    fCur = 0
    prev = A[0]
    if prev == 1:
        tCur = 1
    else:
        fCur = 1
    for idx in range(1, len(A)):
        if A[idx] == prev:
            if prev == 1:
                tCur += 1
            else:
                fCur += 1
        else:
            if prev == 1:
                B.append(tCur)
                tCur = 0
                fCur = 1
            else:
                B.append(-fCur)
                fCur = 0
                tCur = 1
        prev = A[idx]

    if fCur != 0:
        B.append(-fCur)
    if tCur != 0:
        B.append(tCur)

    # print(B)
    # print(maxSubArray(B))
    # print(minSubArray(B))

    if len(B) == 1:
        print(1+abs(maxSubArray(B)))
    else:
        print(1+maxSubArray(B)-minSubArray(B))


solve()
