from operator import itemgetter

N = int(input())

A = []  # AOKI
B = []  # TKHS
D = []  # DIFF

for i in range(N):
    x = [int(i) for i in input().split()]
    A.append(x[0])
    B.append(x[1])
    D.append((x[0], x[1], 2*x[0]+x[1]))

D = sorted(D, key=itemgetter(2), reverse=True)

AOKI = sum(A)
TKHS = 0

c = 0
for v in D:
    if TKHS > AOKI:
        break
    c += 1
    AOKI -= v[0]
    TKHS += v[0] + v[1]

print(c)
