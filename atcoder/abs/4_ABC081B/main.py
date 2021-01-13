def check(n):
  if n%2 == 1:
    return 0
  return n/2

n = int(input())
a = list(map(int, input().split(' ')))

ans = 0
while(0 not in a):
  a = list(map(check,a))
  ans += 1

print(ans-1)
