# Steps to run
# python3 MSV.py

from bisect import bisect_left,bisect

#take inputs
for t in range(int(input())):
    n = int(input())
    arr = [int(i) for i in input().split()]

    # initialise list to store star values of each element
    star = [0 for i in range(n)]

    max_val = max(arr)

    # store index of inputs in dictionary (allows faster lookup)
    d = dict()
    for i,j in enumerate(arr):
        if j in d:
            d[j].append(i)
        else:
            d[j] = [i]

    for i in range(n):
        # skip if the value is not the last occurence in the list (since all previous occurences will have lower star value)
        if arr[i] in d and i != d[arr[i]][-1]:
            continue

        # find all multiples of the value of i
        for j in range(arr[i],max_val+1,arr[i]):
            # if multiple exists in the list, find the no of elements that occur before the no
            if j in d:
                count = bisect_left(d[j],i)
                # update the star value
                star[i] += count

    print(max(star))