from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    D = int(input())
    O = oct(D)

    count = 0
    i = 1
    while i <= D:
        if ('7' not in str(i) and '7' not in str(oct(i))):
            count += 1
        i += 1
    print(count)
