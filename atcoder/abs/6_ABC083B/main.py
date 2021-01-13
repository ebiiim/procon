n, a, b = map(int, input().split())

ret = 0
for i in range(1, n+1):
  x = sum((list(map(int, str(i)))))
  if x >= a and x <= b:
    ret += i
    
print(ret)
