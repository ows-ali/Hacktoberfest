# Problem link: https://www.hackerrank.com/challenges/word-order/problem

num = int(input())
dic = {}
words = []
for i in range(num):
    word = input()
    if word not in dic:
        dic[word] = 1
        words.append(word)

    else: 
        dic[word] += 1

line = ""
for key in words:
    line += str(dic[key])+ " "

line = line.rstrip(' ')

print(len(dic))
print(line)
print("Hacktoberfest")