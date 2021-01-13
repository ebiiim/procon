N = input()

A = {}
B = {}

for i in range(int(N)):
    x = input()
    if x[0] == "!":
        B[x[1:]] = True
    else:
        A[x] = True

ret = "satisfiable"
for k in A:
    if k in B:
        ret = k

print(ret)
