from functools import reduce
import math
from py import lib

A, B = 1, 20
D = [lib.trial_division(n) for n in range(A, B+1)]
DD = []
for d in D:
    tmp = [x for x in DD]  # copy
    for v in d:
        try:
            tmp.remove(v)
        except:
            DD.append(v)

print(reduce((lambda x, y: x*y), DD, 1))
