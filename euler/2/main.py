from py import lib

f = lib.next_fib_fn()
sum = 0
while True:
    a = f()
    if a > 4000000:
        print(sum)
        break
    if a % 2 == 0:
        sum += a
