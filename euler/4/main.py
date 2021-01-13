from py import lib

H, W = 999, 999
L = sum([[(w+1)*(h+1) for w in range(100, W)] for h in range(100, H)], [])
LL = [l for l in L if lib.is_palindrome(l)]
print(max(LL))
