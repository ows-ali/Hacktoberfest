// https://www.codechef.com/problems/DECINC

n=int(input())
def div(a):
	return a+1 if a%4==0 else a-1
print(div(n))
