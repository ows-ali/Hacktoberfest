def inp(v,c):
        
        choice=input("+/-\n")
        if(choice=='+'):
                c+=1
                v+=1
                print(v)
                print(c)
                f=check(v)
                if f==1:
                      inp(v,c)
                      check(v)
                else:
                        print(c)
                        

        else:
                c+=1
                v-=1
                #print(v)
                #print(c)
                f=check(v)
                #print(f)
                if f==1:
                      inp(v,c)
                      #print(v)
                      check(v)
                else:
                        print(c)
                
def check(v):
        f=0
        l=len(str(v))
        l=l-1
        n=10**int(l)
        while v>0:
              r=v//n
              v=v%n
              if not(r%2==0):
                         f=1
                         break
              n=n//10
        return f
        
        
a=input('enter integer\n')
c=0
value=int(a)    #11
f=check(value)   #11
if f==1:
        inp(value,c)
else:
        print(0)
