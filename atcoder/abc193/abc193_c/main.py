

def getset():
    ss = dict()
    MAX_ = 100001
    i = 2
    j = 2
    while i < MAX_:
        j = 2
        while True:
            if i ** j > 10000000000:
                break
            # print(f"put {i} {j} {i ** j}")
            ss[i**j] = True
            j += 1
        i += 1
    return sorted(ss)


def solve():
    N = int(input())

    # N = 100000
    ss = getset()
    # print(len(ss))
    cnt = 0
    for k, v in enumerate(ss):
        if v <= N:
            cnt += 1
            # print(v)

    print(N-cnt)


solve()
