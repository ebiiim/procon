from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    A, B, C, D = input().split()
    print(min([int(A),int(B),int(C),int(D)]))
