# WIP
N = int(input())

NODE = [[] for i in range(N+1)]
NODEV = [0 for i in range(N+1)]

EDGE = [[], ]

# print(NODE)
# print(NODEV)

for i in range(N-1):
    x = [int(i) for i in input().split()]
    NODE[x[0]].append(x[1])
    NODE[x[1]].append(x[0])
    EDGE.append(x)

# print(NODE)
# print(EDGE)

Q = int(input())

QS = []
for i in range(Q):
    QS.append([int(i) for i in input().split()])

print(QS)

for q in QS:
    start = -1
    stopby = -1
    if q[0] == 0:
        start = EDGE[q[1]][0]
        stopby = EDGE[q[1]][1]
    elif q[0] == 1:
        start = EDGE[q[1]][1]
        stopby = EDGE[q[1]][0]
    else:
        print("XXX")
        exit(-1)

    addset = [start]

    # TODO: DFS
    # for n in :
    #    addset.append(n)

    addset = set(addset)
    for v in addset:
        NODEV[v] += q[2]

for v in NODEV[1:]:
    print(v)
