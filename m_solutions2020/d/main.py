# WIP

from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':

    N = input()
    A = [int(i) for i in input().split()]
    N = int(N)

    D = [False for _ in range(N)]

    prev = 0
    prevF = "sell"
    for i, n in enumerate(A):
        if i == 0:
            continue
        print(prevF, A[prev], A[i])
        if prevF == "sell" and A[prev] < A[i]:
            D[prev] = True
            prev = i
            prevF = "buy"
            continue
        if prevF == "buy" and A[prev] > A[i]:
            D[prev] = True
            prev = i
            prevF = "sell"

    print(D)
