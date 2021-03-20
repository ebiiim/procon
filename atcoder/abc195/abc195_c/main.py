# WA
def solve():
    N = int(input())
    FirstN = N
    cnt = 0

    if FirstN > 999:
        N -= 999

    if FirstN > 999_999:
        N -= 999_999 - 999
        cnt += 999_999 - 999 * 1
    else:
        cnt += N * 1
        print(cnt)
        return

    if FirstN > 999_999_999:
        N -= 999_999_999 - 999_999
        cnt += (999_999_999 - 999_999) * 2
    else:
        cnt += N * 2
        print(cnt)
        return

    if FirstN > 999_999_999_999:
        N -= 999_999_999_999 - 999_999_999
        cnt += (999_999_999_999 - 999_999_999) * 3
    else:
        cnt += N * 3
        print(cnt)
        return

    if FirstN > 999_999_999_999_999:
        N -= 999_999_999_999_999 - 999_999_999_999
        cnt += (999_999_999_999_999 - 999_999_999_999) * 4
    else:
        cnt += N * 4
        print(cnt)
        return

    if FirstN > 999_999_999_999_999_999:
        N -= 999_999_999_999_999_999 - 999_999_999_999_999
        cnt += (999_999_999_999_999_999 - 999_999_999_999_999) * 5
    else:
        cnt += N * 5
        print(cnt)
        return


solve()
