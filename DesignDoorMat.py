N,M = input().split()
N = int(N)
M = int(M)
var1 = int((M-7)/2)
var2 = int((M-3)/2)
var3 = 1
for i in range(1, int((N-1)/2)+1):
    print('-'*var2+'.|.'*var3+'-'*var2)
    var3+=2
    var2-=3
print('-'*var1+'WELCOME'+'-'*var1)
for i in range(1, int((N-1)/2)+1):
    print('-'*(var2+3)+'.|.'*(var3-2)+'-'*(var2+3))
    var3-=2
    var2+=3
            

