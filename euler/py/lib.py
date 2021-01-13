import math


def next_fib_fn():
    a, b = 0, 1

    def fib():
        nonlocal a, b
        c = a + b
        a = b
        b = c
        return c
    return fib


def get_primes(n: int) -> list:
    if n < 2:
        return []

    def find_first_true(l):
        for i, b in enumerate(l):
            if b:
                return i
        return 0
    p = []
    a = [True for i in range(n+1)]
    a[0] = False
    a[1] = False
    x = math.sqrt(n)
    while True:
        v = find_first_true(a)
        if v > x:
            [p.append(i) for i, b in enumerate(a) if b]
            break
        p.append(v)
        i = 1
        while v*i < len(a):
            a[v*i] = False
            i += 1
    return p


def trial_division(n: int) -> list:
    pf = []
    pp = get_primes(int(math.sqrt(n)))
    for p in pp:
        while n % p == 0:
            pf.append(p)
            n //= p
    if n != 1:
        pf.append(n)
    return pf


def count_digit(n: int) -> int:
    i = 1
    while n//10**i != 0:
        i += 1
    return i


def reverse_number(n: int) -> int:
    digit = count_digit(n)
    return sum([(n//10**d % 10) * (10**(digit-1-d)) for d in range(digit)])


def is_palindrome(n: int) -> bool:
    return n == reverse_number(n)
