from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    A, B, C = input().split()
    K = input()
    A, B, C, K = int(A), int(B), int(C), int(K)

    for k in range(K):
        if not B > A:
            B *= 2
            continue
        if not C > B:
            C *= 2
            continue

    if C > B > A:
        print("Yes")
    else:
        print("No")
