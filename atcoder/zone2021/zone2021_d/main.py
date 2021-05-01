from collections import deque


def solve():
    N = input()

    isrev = False

    ans = deque()

    for c in N:
        if c == "R":
            isrev = not isrev
            continue
        if len(ans) == 0:
            ans.append(c)
            continue
        if not isrev:
            tmp = ans.pop()
            if tmp != c:
                ans.append(tmp)
                ans.append(c)
        if isrev:
            tmp = ans.popleft()
            if tmp != c:
                ans.appendleft(tmp)
                ans.appendleft(c)

    if isrev:
        ans.reverse()
    anss = ""

    for _ in range(len(ans)):
        anss += ans.popleft()
    print(anss)


solve()
