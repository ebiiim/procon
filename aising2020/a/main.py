from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    L, R, d = input().split()
    L, R, d = int(L), int(R), int(d)

    print(len([v for v in range(L, R+1) if v % d == 0]))
