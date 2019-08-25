def migratoryBirds(arr):
    dct = {}
    # creating a dictionary of all the unique bird counts
    for elem in arr:
        if elem in dct:
            dct[elem] += 1
        else:
            dct[elem]=1
    
    # returning the first set of a sorted dict, picking its key value
    return sorted(dct.items(), key=lambda x: x[1], reverse=True)[0][0]




