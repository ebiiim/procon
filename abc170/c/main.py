from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    pass
    # N = input()
    # X, Y, Z = input().split()
    # A = [int(i) for i in input().split()]
    X, N = input().split()
    X, N = int(X), int(N)
    if N == 0:
        print(X)
        exit(0)
    P = [int(i) for i in input().split()]
    P = list(set(P))

    i = 0
    while True:
        v = X-i
        if not (v in P):
            print(v)
            exit(0)
        v = X+i
        if not (v in P):
            print(v)
            exit(0)
        i += 1
