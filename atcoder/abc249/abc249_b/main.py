def solve():
    S = input()

    d = set()
    dup = False
    u = False
    l = False
    for c in S:
        if c.isupper():
            u = True
        if c.islower():
            l = True
        if c not in d:
            d.add(c)
        else:
            dup = True

    if (not dup) and u and l:
        print("Yes")
    else:
        print("No")


solve()
