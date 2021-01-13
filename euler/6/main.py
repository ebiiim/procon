A = 1
B = 100
C = sum([v*v for v in range(A, B+1)])
D = sum(range(A, B+1))
print(D*D-C)
