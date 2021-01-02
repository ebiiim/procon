A, B = input().split()

a = 0
for c in A:
    a += int(c)

b = 0
for c in B:
    b += int(c)

if a < b:
    print(b)
else:
    print(a)
