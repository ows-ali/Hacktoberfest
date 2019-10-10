import sys
n = int(input().strip())
arr = [int(arr_temp) for arr_temp in input().strip().split(' ')]
arr.sort(key=int ,reverse=True)
t=True
while(t):
    print(len(arr))
    arr[:] = [x - min(arr) for x in arr]
    
    arr=[x for x in arr if x > 0 ]
    if(len(arr)<1):
        t=False
    
    

