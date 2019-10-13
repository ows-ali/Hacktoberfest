N, M = map(int,input().split()) # More than 6 lines of code will result in 0 score. Blank lines are not counted.
for i in range(1,N,2): 
    print('-'*((M-3*i)//2)+'.|.'*i+'-'*((M-3*i)//2))
print(((M-7)//2)*'-'+'WELCOME'+((M-7)//2)*'-')
for i in range(N-2,-1,-2): 
    print('-'*((M-3*i)//2)+'.|.'*i+'-'*((M-3*i)//2))
