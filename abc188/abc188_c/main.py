N = input()
A = [int(i) for i in input().split()]
A1 = A[:(len(A)//2)]
A2 = A[(len(A)//2):]
# print(A1)
# print(A2)
MA1 = max(A1)
MA2 = max(A2)
l = A1.index(MA1)
r = A2.index(MA2)
# print(l)
# print(r)
if MA1 < MA2:
    print(l+1)
else:
    print(r+len(A)//2+1)
