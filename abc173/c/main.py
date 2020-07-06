# WA

from sys import stdin

def readline_from_stdin() -> str:
    return stdin.readline().rstrip

def cT(c) -> int:
    ccc = [cc.count(True) for cc in c]
    return sum(ccc)

def sortFn(c) -> list:
    nl = sorted(c, key=lambda x: x.count(True), reverse=True)
    return nl

def compFn(c) -> list:
    return [cc.count(True) for cc in c]

def combiFn(c) -> list:
    combi = [list(itertools.combinations(c, v)) for v in range(len(c))]
    combina = [ [ list(v)  for v in vvv]    for vvv in combi]
    return list(itertools.chain.from_iterable(combina))
    # return combina

def countCombiFn(c, X) -> int:
    combiSum = [list(itertools.combinations(c, v)) for v in range(len(c))]
    combinaSum = [ [list(v) for v in vvv] for vvv in combiSum]
    f1 = list(itertools.chain.from_iterable(combinaSum))
    # print(len(f1))
    # f2 = list(itertools.chain.from_iterable(f1))
    sumF1 = [sum(v) for v in f1]
    # print(sumF1)
    # print(sumF1.count(X))
    return sumF1.count(X)


if __name__ == '__main__':
    import itertools

    H, W, K = input().split()
    H, W, K = int(H), int(W), int(K)

    C = [[False if i == "." else True for i in input()] for i in range(H)]
    # sC = sortFn(C)
    comped = compFn(C)
    combi = combiFn(comped)
    # print(len(combi))
    # print(combi)
    cntArr = [countCombiFn(c, K) for c in combi]
    # print(cntArr)
    print(sum(cntArr))
    # print(sum(cntArr))

