from itertools import permutations
def word_value(w):
    place = 1
    value = 0
    for i in w[::-1]:
        value+=ord(i)*place
        place*=10
    return (value)
def biggerIsGreater(w):   
    #My Method
                              
    p = list(permutations(w))   #List all possible permutations
    value = word_value(w)       #Takes value of the word through "w[-1]*10^0 + w[-2]*10^1 + w[-3]*10^2 ......."
    value_diff_list = [word_value(i) - value for i in p]    #Takes value for each permutation
    indexes = [value_diff_list.index(x) for x in value_diff_list if x <= 0] #lists indexes of elements whose number value is less than word"
    for i in sorted(indexes,reverse = True):
        p.pop(i)                        #Removes permutations with above indices
        value_diff_list.pop(i)
    if(len(p)>0):         #If there still remains any permutations
        index = value_diff_list.index(min(value_diff_list))     #Find the permutation with min val difference between the permutation and word and return the permutation
        return "".join(p[index])
    else:
        return 'no answer'  #If empty there is no possible answer

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
         




print(biggerIsGreater('dkhc'))
print(nextpermutation('dkhc'))



    
    
