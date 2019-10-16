n = int(input())

for i in range(n):

	l = list(map(int,input()))
    
	count = 0
   
	for i in l:

		if i == 4:

			count += 1
    
	print(count)