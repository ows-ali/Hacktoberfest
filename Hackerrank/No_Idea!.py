n,m = input().split()
arr = input().split()
set_A = input().split()
set_B = input().split()

set_A = set(set_A)
set_B = set(set_B)

print(sum([(item in set_A) - (item in set_B) for item in arr]))