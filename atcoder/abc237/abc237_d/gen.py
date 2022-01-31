# create large data

# a.in
# print(500000)
# print('R' * 500000)

# a.out
S = ''
for i in range(0, 500001):
    S += str(i)
    S += " "
print(S[:-1])
