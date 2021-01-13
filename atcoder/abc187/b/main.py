import itertools
N = input()

A = []
for _ in range(int(N)):
    X, Y = input().split()
    A.append((int(X), int(Y)))

# print(A)

C = itertools.combinations(A, 2)

# print(list(C))

count = 0

for c in C:
    x1, y1, x2, y2 = c[0][0], c[0][1], c[1][0], c[1][1]
    if x2-x1 == 0:  # div by zero
        continue
    slope = (y2-y1)/(x2-x1)
    if (slope >= -1) and (slope <= 1):
        count += 1

print(count)
