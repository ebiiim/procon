def solve():

    LT = "<"
    GT = ">"
    EQ = "="
    ans = ""

    A, B, C = map(int, input().split())

    C = C % 2 + 2

    if pow(A, C) < pow(B, C):
        print(LT)
    elif pow(A, C) == pow(B, C):
        print(EQ)
    else:
        print(GT)

    # if A == B:
    #     ans = EQ

    # elif A == 0:
    #     if B == 0:
    #         ans = EQ
    #     elif B > 0:
    #         ans = LT
    #     elif B < 0:
    #         if C % 2 == 1:
    #             ans = GT
    #         else:
    #             ans = LT

    # elif A < 0:
    #     if B == 0:
    #         if C%2 == 1:
    #             ans = LT
    #         else:
    #             ans = GT
    #     elif B > 0:

    #     if C % 2 == 1:
    #         if A < B:
    #             ans = GT
    #         else:
    #             ans = LT
    #     else:
    #         if A < B:
    #             ans = LT
    #         else:
    #             ans = GT

    # elif A > 0:
    #     if

    # print(ans)


solve()
