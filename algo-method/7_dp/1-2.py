def solve():
  N = int(input())
  A = [int(i) for i in input().split()]
  
  ans = [0] * N

  ans[0] = 0
  ans[1] = A[1]

  for i in range(2, N):
    a1 = ans[i-1] + A[i]
    a2 = ans[i-2] + A[i]*2
    ans[i] = min(a1, a2)

  print(ans[N-1])

solve()
