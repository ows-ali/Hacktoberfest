# Complete the divisibleSumPairs function below.
def divisibleSumPairs(n, k, ar):
    cnt = 0
    for i in range(0, len(ar)-1):
        for j in range(i+1, len(ar)):
            if((ar[i] + ar[j])%k ==0):
                cnt +=1
    
    return cnt

