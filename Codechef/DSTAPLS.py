def comp(a1,a2,k):
	for i in range(k):
		if(a1[i]!=a2[i]):
			return "YES"
	return "NO"


t = int(input())
for i in range(t):
	n,k = map(int,input().split())
	if((n//k)%k==0):
		print("NO")
	else:
		print("YES")
