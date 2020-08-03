a = int(input())  # 500
b = int(input())  # 100
c = int(input())  # 50
x = int(input())

ans = 0

for A in range(a+1):
  for B in range(b+1):
    for C in range(c+1):
      if (A*500 + B*100 + C*50 == x):
        ans += 1

print(ans)
