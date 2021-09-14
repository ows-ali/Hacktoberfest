
import sys
 
queue = int(raw_input().strip())

for a0 in xrange(queue):

    x,y,z = raw_input().strip().split(' ')
    x,y,z = [int(x),int(y),int(z)]
    cA = abs(x-z)
    cB = abs(y-z)
	
    if (cA < cB):
        print "Cat A"
    elif (cB < cA):
        print "Cat B"
    else:
        print "Mouse C"