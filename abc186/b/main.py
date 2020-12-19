from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    H, W = int(input().split())
    H, W = int(H), int(W)

    i = 0
    A = []
    while i < H:
        A += [int(i) for i in input().split()]
        i += 1
    A.sort()

    v = A[0]
    print(sum([a-v for a in A]))
