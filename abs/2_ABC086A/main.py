a, b = map(int, input().split(' '))
ans_list = ['Even', 'Odd']
print(ans_list[(a*b)%2])
