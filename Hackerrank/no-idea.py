#https://www.hackerrank.com/challenges/no-idea/
# Enter your code here. Read input from STDIN. Print output to STDOUT
'''x=input()
l1=input()
l2=input()
l3=input()
li0=x.split(" ")
h=0
if((int(li0[0])>1) & (int(li0[1])>1)):
    li1=l1.split(" ")

    li2=l2.split(" ")
    li3=l3.split(" ")
    la=[]
    lb=[]
    for i in li2:
        la.append(int(i))  
    for i in li3:
        lb.append(int(i))
    for i in li1:
        if int(i)  in la:
            h+=1
        elif int(i) in lb:
            h-=1    
elif((int(li0[0])==1) & (int(li0[1])>1)):
    li1=int(l1)
    li2=l2.split(" ")
    li3=l3.split(" ")
    la=[]
    lb=[]
    for i in li2:
        la.append(int(i))  
    for i in li3:
        lb.append(int(i))
    if li1  in la:
        h+=1
    elif li1 in lb:
        h-=1    
elif((int(li0[0])>1) & (int(li0[1])==1)):
    la=int(l2)
    lb=int(l3)
    li1=l1.split(" ")
    for i in li1:
        if(int(i)==la):
            h+=1
        elif(int(i)==lb):
            h-=1    
    
print(h)  '''  
        
_ = input()
array = input().split()
like = set(input().split())
dislike = set(input().split())
print(sum((i in like) - (i in dislike) for i in array))
