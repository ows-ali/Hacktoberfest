k = int(input())

for number in range(k):
    s = input()
    number_of_times = []
    finno = []
    k = 0
    for i in s:
        k = 0
        for letter in s:
            if letter == i:
                k+=1
                a = s.index(letter)
                s = s[:a:]+s[a+1::]
        number_of_times.append(k)

    dynam = True
    for i in number_of_times:
        if i!=0:
            finno.append(i)

    finno = sorted(finno)

    if len(finno) >= 3:
        #for i in range(2,len(finno)):
        i = len(finno) - 1
        if finno[i] == finno[i-1]+finno[i-2]:
            dynam = dynam and True
        else:
            dynam = dynam and False
    if dynam==True or len(finno)<3:
        print("Dynamic")
    else:
        print("Not")

