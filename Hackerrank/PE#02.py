def fib(n, computed = {0: 0, 1: 1}):
    if n not in computed:
         computed[n] = fib(n-1, computed) + fib(n-2, computed)
    return computed[n]
for _ in range(int(input())):
 num=int(input())
 s=0
 for i in range(1,num):
    
    
    if fib(3*i)>=num:
        break
    s=fib(3*i)+s

 print(s)
 
