from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    D = {9: 1, 8: 2, 7: 3, 6: 4, 5: 5, 4: 6, 3: 7, 2: 8}
    X = int(input())
    print(D[X//200])
