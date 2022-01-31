def solve():

    S = input()
    S = list(S)

    frontA = 0
    for s in S:
        if s == "a":
            frontA += 1
        else:
            break

    S.reverse()

    backA = 0
    for s in S:
        if s == "a":
            backA += 1
        else:
            break

    # print(frontA, backA)
    # print(S)

    if backA < frontA:
        print("No")
        exit(0)

    AS = "a" * (backA - frontA)
    S2 = S + list(AS)

    s1 = ''.join(S2)
    s2 = reversed(list(s1))
    s2 = ''.join(s2)

    if s1 == s2:
        print("Yes")
    else:
        print("No")


solve()
