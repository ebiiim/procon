N, M = input().split()
N, M = int(N), int(M)
A = [int(i) for i in input().split()]

A = [0] + A + [N+1] # add sentinels
A.sort()

B = [-1] * (len(A) -1) # diff array
i=0
while i<len(A)-1:
    x, y = A[i], A[i+1]
    B[i] = y-x-1
    i += 1

C = [v for v in B if v != 0] # remove 0
C.sort()

if len(C) == 0:
    print('0')
else:
    k = C[0]
    D = [c//k if c%k==0 else c//k+1 for c in C]
    print(sum(D))
