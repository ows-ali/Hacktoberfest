daystart=int((input().split())[1])
b=input().split()

d=[c for c in b if (c!=':')]
start=[]
for i in range(len(d)):
    if d[i][0]=="0":
        start.append(int(d[i].replace("0","")))
    else:
        start.append(int(d[i]))

dayend=int((input().split())[1])
s=input().split()

p=[c for c in s if (c!=':')]
end=[]
for i in range(len(p)):
    if p[i][0]=="0":
        end.append(int(p[i].replace("0","")))
    else:
        end.append(int(p[i]))
Hour=end[0]-start[0]
Day=dayend-daystart
if Hour<0:
  Hour=Hour+24
  Day=Day-1
Minute=end[1]-start[1]
if Minute<0:
  Minute=Minute+60
  Hour=Hour-1    
Second=end[2]-start[2]
if Second<0:
  Second=Second+60
  Minute=Minute-1
if Day<=0:
  Day=0
print(Day ,"dia(s)")
print(Hour ,"hora(s)")
print(Minute ,"minuto(s)")
print(Second ,"segundo(s)")