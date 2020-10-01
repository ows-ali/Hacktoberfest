# Link to the problem https://www.codechef.com/SEPT20B/problems/ADAMAT
for _ in range(int(input())):
    n = int(input())
    opts = 0
    list1 = []
    column = n
    for i in range(n):
        l = list(map(int, input().split()))
        list1.append(l)
    for i in range(n - 1, 0, -1):
        fixed_element = list1[i][i]
        changing_element = list1[i][i - 1] + 1
        if fixed_element != changing_element:
            opts = opts + 1
            c = i + 1
            for i in range(c):
                for j in range(i, c):
                    list1[i][j], list1[j][i] = list1[j][i], list1[i][j]
    print(opts)
