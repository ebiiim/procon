# WA

def solve(N, S, K):
    loop = S % K
    c = 0
    while True:
        print("-----")
        print("S=", S)
        print("(N-S)//K=", (N-S)//K)
        print("(N-S)%K=", (N-S) % K)
        print("c=", c)
        c += (N-S)//K
        print("c=", c)
        if (N-S) % K == 0:
            return c
        else:
            c += 1
            print("c=", c)
        S = (N-S) % K
        if S == loop:
            print("LOOP!")
            return -1


if __name__ == '__main__':
    # T = int(input())
    # for _ in range(T):
    #     N, S, K = input().split()
    #     N, S, K = int(N), int(S), int(K)
    #     print(solve(N, S, K))

    # print(solve(10, 4, 3))
    # print(solve(10, 4, 4))
    # print(solve(10, 5, 2))
    # print(solve(1000, 11, 2))
    print(solve(10000, 6, 14))
