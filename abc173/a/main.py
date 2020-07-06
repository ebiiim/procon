from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    N = int(input())
    a = 1000 - N % 1000
    if a == 1000:
        a = 0
    print(a)
