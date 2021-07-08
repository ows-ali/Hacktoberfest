from math import log10, ceil, sqrt

phi = (1+sqrt(5))/2           
for _ in range(int(input())):
    d = int(input())    

    n = ceil((log10(5)/2 + d - 1) / log10(phi))   #phi^n / sqrt(5) > 10^(d-1)
    print(int(n))
