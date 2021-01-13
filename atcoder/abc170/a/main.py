from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    pass
    # N = input()
    # X, Y, Z = input().split()
    # A = [int(i) for i in input().split()]
    X = [int(i) for i in input().split()]
    for idx, v in enumerate(X):
        if v == 0:
            print(idx+1)
            exit(0)
