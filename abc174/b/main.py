from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    N, D = input().split()
    N, D = int(N), int(D)

    c = 0
    for i in range(N):
        X, Y = input().split()
        X, Y = int(X), int(Y)
        if X*X + Y*Y <= D*D:
            c += 1
    print(c)
