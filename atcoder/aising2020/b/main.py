from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    N = int(input())
    A = input().split()
    a = [int(v) for _, v in enumerate(A)]
    print(len([v for i, v in enumerate(a) if (i+1) % 2 != 0 and v % 2 != 0]))
