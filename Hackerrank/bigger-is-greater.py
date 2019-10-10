#from itertools import permutations
def word_value(w):
    place = 1
    value = 0
    for i in w[::-1]:
        value+=ord(i)*place
        place*=10
    return (value)


def nextpermutation(w):
    w1 = list(w)
    for i in range(len(w))[::-1]:   #Reversing to find largest index    
        if w[i-1]<w[i]:             #Finding Largest index i till where the sequence remains in non-ascending order(till !(array[i-1]<array[i]))
            for j in range(i,len(w))[::-1]: 
 #Finding Largest index j for which array[j] > array[i-1](array[i-1] contains the element due to which lower word value is given , So j is used to find the minimum element required to find the next permutation(i.e. slightly greater word_value)) 
                if w[i-1] < w[j]:
                    #swapping array[j] element with array[i-1] to bring the (slightly) higher value elements to the beginning increasing word value
                    w1[i-1],w1[j] = w1[j],w1[i-1]
                    #Reversing the array from i th element (largest element of subarray a[i:]) to the end and concatenating   
                    if(word_value(w1)-word_value(w)>0):
                        return("".join(w1[:i]+w1[i::][::-1]))
                    else:    
                        return 'no answer' 
    return 'no answer'                             
         


#print(nextpermutation('dkhc'))



    
    
