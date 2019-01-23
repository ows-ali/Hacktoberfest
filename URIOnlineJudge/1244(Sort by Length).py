n = int(input())
for i in range(n):
    str_list = input().split()
    print(" ".join(sorted(str_list, key=len, reverse=True)))