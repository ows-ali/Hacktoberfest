# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input())
wordCount = dict()
for i in range(n):
    s = input()
    if s in wordCount:
        wordCount[s] += 1
    else:
        wordCount[s] = 1

countList = []
for value in wordCount.values():
    countList.append(str(value))

print(len(wordCount))
print(' '.join(countList))
