from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    pass
    # N = input()
    # X, Y, Z = input().split()
    # A = [int(i) for i in input().split()]
    X, Y = input().split()
    X = int(X)
    Y = int(Y)

    b = (X*2-Y)/(-2)
    a = X-b
    # print(a, b)
    if not a.is_integer() or not b.is_integer() or a < 0 or b < 0:
        print("No")
        exit(0)
    print("Yes")
