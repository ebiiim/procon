n = int(input())
a = list(map(int, input().split()))
a.sort()
a.reverse()
alice = a[::2]
bob = a[1::2]
print(sum(alice)-sum(bob))
