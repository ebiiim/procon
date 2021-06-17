def solve():
    K, X = map(int, input().split())
    s = ""
    x = X-K+1

    for i in range(K*2-1):
        s += str(x) + " "
        x += 1
    print(s[:-1])


solve()
