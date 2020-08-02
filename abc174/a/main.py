from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    X = int(input())
    if X >= 30:
        print("Yes")
    else:
        print("No")
