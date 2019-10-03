
#https://www.hackerrank.com/challenges/find-second-maximum-number-in-a-list/problem

num int(input())
score= list(map(int, input().split()))
 
z = max(score)
while max(score) == z:
    score.remove(max(score))

print (max(score))