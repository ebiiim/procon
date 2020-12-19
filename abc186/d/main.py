N = input()

A = [int(i) for i in input().split()]
A.sort(reverse=True)

L = len(A)
LEFT = 0
RIGHT = 0
i = 0
while i < L:
    LEFT += A[i] * (L-i-1)
    RIGHT += A[L-i-1] * (L-i-1)
    i += 1
print(LEFT-RIGHT)
