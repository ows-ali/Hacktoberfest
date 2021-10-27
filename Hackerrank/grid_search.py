t = int(input())


def grid_search(tc):
    for i in range(0, tc):
        r_g,c_g =[ int(size) for size in str(input()).split(" ")]
        grid_to_be_searched = [ str(input()) for row in range(0,r_g) ]

        #print(grid_to_be_searched)

        r_p, c_p = [ int(size) for size in str(input()).split(" ")]
        pattern_to_search  = [ str(input()) for row in range(0,r_p) ]

        #print(pattern_to_search)

        row_of_pat = 0
        start_index = 0
   
        for col in range(0, c_g):
            #print(col)
            for j in range(0, r_g):
                row_of_pat = 0
                col_to_be_searched = ''.join(list(grid_to_be_searched[j])[col: c_g])
                #print(col_to_be_searched, row_of_pat)
                find_count = 0
                start_index = str(col_to_be_searched).find(pattern_to_search[row_of_pat])
                #print("start_index: " , start_index)
                if start_index != -1:
                    find_count+=1
                    row_of_pat += 1
                    l = j
                    for k in range( row_of_pat,  r_p):

                        l += 1
                        if l >= r_g:
                            break
                        #print(list(grid_to_be_searched[l])[start_index+col: start_index+col+c_p])
                        if ''.join(list(grid_to_be_searched[l])[start_index+col: start_index+c_p+col]) != pattern_to_search[k]:
                            row_of_pat = 0
                            break 
                        else:
                            find_count+=1
                    if find_count == r_p:
                        break
            if find_count == r_p:
                break
                        

                    
        #print(find_count)
        if find_count == r_p:
            print("YES")
        else:
            print("NO")

grid_search(t)