import math


def sum1(n):
    return (n * (n+1)) // 2


def lcm(x, y):
    return (x * y) // math.gcd(x, y)


def solve():
    N, A, B = map(int, input().split())
    print(sum1(N) - A*sum1(N//A) - B*sum1(N//B) +
          (lcm(A, B))*sum1(N//lcm(A, B)))


solve()
