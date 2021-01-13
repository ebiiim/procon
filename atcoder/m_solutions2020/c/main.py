from sys import stdin


def readline_from_stdin() -> str:
    return stdin.readline().rstrip


if __name__ == '__main__':
    N, K, = input().split()
    A = [int(i) for i in input().split()]
    N, K = int(N), int(K)

    for i in range(N-K):
        if A[i] < A[K+i]:
            print("Yes")
        else:
            print("No")

    # score = 1
    # for i in range(K):
    #     score *= A[i]

    # for i in range(N-K):
    #     new_score = int(score / A[i]) * A[K+i]
    #     if new_score > score:
    #         print("Yes")
    #     else:
    #         print("No")
    #     score = new_score

    # scores = [score]
    # for i in range(N-K):
    #     print(i, K+i)
    #     score = int(score / A[i]) * A[K+i]
    #     scores.append(score)
    #
    # print(scores)
    #
    # results = [False for i in range(len(scores)-1)]
    #
    # for i in range(len(scores)-1):
    #     results[i] = scores[i+1] > scores[i]
    #
    # [print("Yes") if r else print("no") for r in results]
