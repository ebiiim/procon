from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    N = int(input())
    S = [input() for i in range(0, N)]

    print("AC x", S.count("AC"))
    print("WA x", S.count("WA"))
    print("TLE x", S.count("TLE"))
    print("RE x", S.count("RE"))
