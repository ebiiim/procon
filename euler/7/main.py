from py import lib

b = 1
while True:
    ps = lib.get_primes(b)
    if len(ps) >= 10001:
        print(ps[10001-1])
        break
    b <<= 1
