def solve():
    A, B = map(int, input().split())
    
    if 0 < A and B == 0:
        print("Gold")
    if A == 0 and 0 < B:
        print("Silver")
    if 0 < A and 0 < B:
        print("Alloy")


solve()
