#URL: https://www.hackerrank.com/challenges/2d-array/problem
def hourglassSum(arr):
    n = 6
    m = 6
    maxsum = arr[0][0]+arr[0][1]+arr[0][2]+arr[1][1]+arr[2][0]+arr[2][1]+arr[2][2]
    for i in range(0,n-2):
        for j in range(0,n-2):
            ts = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]
            maxsum = max(maxsum,ts)
    return maxsum
