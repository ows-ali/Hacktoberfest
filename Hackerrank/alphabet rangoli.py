#!/bin/python3
# https://www.hackerrank.com/challenges/alphabet-rangoli/problem

#ll=limitting letter
#sl=starting letter
#df=deduction factor
#cd=character difference
#rl=resulting letter
while True:
    ll=ord(input("Enter the limitting letter in the pattern:> "))
    sl=65 if ll in range(65,91) else (97 if ll in range(97,123) else None)
    if sl: break
    print("Enter a valid input.")
print("See the alphabet pattern:>\n")
for df in range(sl-ll,ll-sl+1):
    for cd in range(sl-ll,ll-sl+1):
        rl=sl+abs(cd)+abs(df)
        if(cd==ll-sl):
            print(chr(rl) if rl<=ll else '-')
        else:
            print(chr(rl) if rl<=ll else '-',end="-")
        


    