def solve():
    N, K = map(int, input().split())
    A = [int(i) for i in input().split()]
    B = [int(i) for i in input().split()]

    ansY = "Yes"
    ansN = "No"

    A.reverse()
    B.reverse()

    pa = True
    pb = True
    for idx in range(0, N-1):
        curA = A[idx]
        curB = B[idx]
        nextA = A[idx+1]
        nextB = B[idx+1]
        pA = False
        pB = False
        if pa:
            pA = pA or (abs(curA - nextA) <= K)
            pB = pB or (abs(curA - nextB) <= K)
        if pb:
            pA = pA or (abs(curB - nextA) <= K)
            pB = pB or (abs(curB - nextB) <= K)
        # print(curA, curB, nextA, nextB, pa, pb, pA, pB)
        # print("-----")

        pa = pA
        pb = pB
        if not pa and not pb:
            print(ansN)
            return

    print(ansY)


solve()
