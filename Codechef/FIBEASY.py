def find_index ( number ) : 
	## index = 2^n , where n = int ( log(number,2) ). Thats what will be left, after removing odd indexes
	curr = 1 
	while not curr*2 > number :
		curr = curr*2
	return curr

def bottom_up (n): 
	""" Bottom up construction of fibonacci series, except only the last digit is stored """
	fibs = [0, 1]
	for i in range(2, n+1):
		fibs.append( (fibs[-1] + fibs[-2] ))
	return fibs

def reqd_soln (curr_n, series) : 
	
	final_index = ( find_index(curr_n) - 1 ) % 60 
	print ( series[final_index]%10 )


def main() : 

	tcases = int ( input( "") ) 	
	""" Done only till 60, since after that, the entire pattern repeats """
	series = bottom_up(60)
	
	for t in range(tcases) : 
		curr_n = int ( input("") ) 
		reqd_soln ( curr_n , series )

try:
	main()
except Exception as e:
	print(e)