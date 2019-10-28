# Problem link: https://www.hackerrank.com/challenges/word-order/problem

num=int(input())
d = {}
for i in range(num):
    word = input().strip()
    if word in d:
        d[word][1] += 1
    else:
        d[word] = [i, 1]

print(len(d))
print(' '.join(str(d[x][1]) for x in sorted(d, key = lambda x: d[x][0])))