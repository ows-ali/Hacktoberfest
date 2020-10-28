#URL: https://www.hackerrank.com/challenges/equal-stacks/problem

def equalStacks(h1, h2, h3):
    # Write your code here
    n1 = 0
    n2 = 0
    n3 = 0

    s1 = sum(h1)
    s2 = sum(h2)
    s3 = sum(h3)

    while True:
        print(s1,s2,s3)
        if s1>s2 or s1>s3:
            s1 = s1 - h1[n1]
            n1+=1
        elif s2>s1 or s2>s3:
            s2 = s2 - h2[n2]
            n2+=1
        elif s3>s1 or s3>s2:
            s3 = s3 - h3[n3]
            n3+=1
        else: break
    ans  =min(s1,s2,s3)
    if ans>0:
        return ans
    return 0
