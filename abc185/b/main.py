from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    X, Y, Z = input().split()
    n = int(Y)
    go_home = "Yes"
    b = int(X)
    t = 0
    i = 0
    while i<n:
        i = i+1
        A, B = input().split()
        A, B = int(A), int(B)
        # go
        b -= A-t
        if b <= 0:
            go_home = "No"
            break
        t = A        
        # cafe
        b += B-t
        if b > int(X):
            b = int(X)
        t = B
    # check goal
    b -= (int(Z)-t)
    if b <= 0:
        go_home = "No"
    print(go_home)