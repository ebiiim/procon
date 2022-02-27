import re


def solve():
    N = int(input())
    S = input()

    # S2 = S.replace("BB", "A")
    # S2 = re.sub(r"B(A+)", "\g<1>B", S2)
    # S2 = S2.replace("BB", "A")
    # S2 = re.sub(r"B(A+)", "\g<1>B", S2)
    # S2 = S2.replace("BB", "A")
    # S2 = re.sub(r"B(A+)", "\g<1>B", S2)

    S2 = ""
    tmp = ""
    hasB = False
    for idx in range(len(S)):

        if not hasB:
            if S[idx] == "A":
                S2 += "A"
            elif S[idx] == "B":
                hasB = True
                tmp = ""
            else:  # C
                S2 += "C"
        else:  # hasB
            if S[idx] == "A":
                tmp += "A"
            elif S[idx] == "B":
                S2 += tmp + "A"
                hasB = False
                tmp = ""
            else:  # C
                S2 += tmp + "BC"
                hasB = False
                tmp = ""

    if hasB:
        S2 += tmp + "B"

    print(S2)


solve()
