from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    X, Y = input().split()
    X, Y = int(X), int(Y)
    print(X//Y)
