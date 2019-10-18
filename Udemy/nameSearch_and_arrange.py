'''
This program is meant to take names from file where 
names are given like this:

tom archer lastname jones
om archer lastname jones
lastname huwy hawai dewey
see more surname or-less

and task is to seggregate lastname and first name, middle name, by seeing lastname/surname and parsing it

This code can be tested by text file added in the same folder.
'''

def nameSeparator(line):
	strs=line.rstrip() #Remove trailing whitespace.
	lst=strs.split(' ') #split line in with spaces and store in list
	stri=""
	i=0
	sizeList=len(lst) #calculating the size of list where names are added 
	while (i<sizeList):
		if (lst[i]=='lastname' or lst[i]=='surname'):  #checking the position of lastname or surname
			stri+=lst[i+1].capitalize() #adding the lastname to string
			break
		i+=1
	lst.remove(lst[i]) #removing lastname and 
	lst.remove(lst[i]) #name followed by lastname
	stri+=","
	for j in lst:
		stri+=" "+str(j).capitalize() #adding the rest in order and capitalizing
	print (stri)

def main():
	f=open("namesLast.txt",'r')
	lst=[]
	for line in f:
		nameSeparator(line) #calling name separator function and passing each line as argument

if __name__=='__main__':
	main()