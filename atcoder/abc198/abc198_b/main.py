
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


def solve():
    N = int(input())
    if N == 0:
        print("Yes")
        exit(0)

    while True:
        if N % 10 == 0:
            N = N // 10
        else:
            break
    if is_palindrome(N):
        print("Yes")
    else:
        print("No")


solve()
