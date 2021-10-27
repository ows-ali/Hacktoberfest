t = int(input())


for i in range(0, t):
    n, k = [ int(p) for p in str(input()).split(" ")]
    used_number_dict = dict()
    smalles_per = []
    ps =  True
    for j in range( n,0, -1):
        if j - k != 0:
            min_val = abs(j-k)
            max_val = j + k

            if max_val > n:
                max_val = min_val


            if used_number_dict.get(max_val) == None:
                used_number_dict[max_val] = True
                smalles_per.append(max_val)
            elif used_number_dict.get(min_val) == None:
                used_number_dict[min_val] = True
                smalles_per.append(min_val)
            else:
                ps = False
                break
        elif j-k == 0:
            if used_number_dict.get(j+k) == None and j+k <= n:
                used_number_dict[j+k] = True
                smalles_per.append(j+k)
            else:
                ps = False
                break
    
   
    if ps == False:
        print("-1")
    else:
        print(*smalles_per[::-1])

        
    