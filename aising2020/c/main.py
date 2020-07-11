# TLE

from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


def calc(x, y, z):
    return (x+y+z)*(x+y+z) - (x*y + x*z + y*z)


def calc2(x, y, z):
    return x*x + y*y + z*z + x*y + x*z + y*z


def f(n):
    res = []
    for i in range(1, n+1):
        for j in range(1, n+1):
            for k in range(1, n+1):
                # res.append((i,j,k,calc(i, j, k)))
                res.append(calc(i, j, k))
                # pass
    return res


if __name__ == '__main__':
    N = int(input())

    import time

    # start = time.time()
    res = f(200)
    # elapsed_time = time.time() - start
    # print("elapsed_time:{0}".format(elapsed_time) + "[sec]")

    for i in range(1, N+1):
        print(res.count(i))
