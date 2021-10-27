n = int(input())

arr = [ int(k) for k in str(input()).split(" ")]

sorted_arr  = sorted(arr)

diff_sort = []
start_index = -1
end_index = -1
sort_dict = dict()
k = 0
start_val = 0
for i in range(0, n):
    diff = arr[i] - sorted_arr[i]

    if i == 0 and diff != 0:
        k += 1
        start_index = i+1
        start_val = diff
    elif i < n-1 and diff == 0 and arr[i+1] - sorted_arr[i+1] !=0 and start_val + arr[i+1] - sorted_arr[i+1] != 0:
        start_index = i+2
        k+=1
        start_val = arr[i+1] - sorted_arr[i+1]
    
    if (i == n-1 and diff != 0)  or  (i < n-1 and diff != 0 and arr[i+1] - sorted_arr[i+1] ==0):
        end_index =  i+1
   

    diff_sort.append(diff)
    if diff != 0:
        if sort_dict.get(abs(diff )) == None:
            sort_dict[abs(diff)] = diff
        else: 
            sort_dict[abs(diff)] += diff


#print(sort_dict, k)
#print(diff_sort)
    
not_possible = False
for key in sort_dict.keys():
    if sort_dict[key] != 0:
        not_possible = True
        break
    else:
        continue


if not_possible or k > 1:
    print("no")
else:
    print("yes")
    if len(sort_dict.keys()) == 1:
        print("swap", start_index, end_index)
    else:
        print("reverse", start_index, end_index)
