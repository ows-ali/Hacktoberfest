import math

n,m = [int(i) for i in str(input()).split(" ")]
cities_with_space_station = sorted( [int(i) for i in str(input()).split(" ")] )

#print("cities_with_space_station: ", cities_with_space_station)

cities_without_space_station = []

longest_chain = []
cities = []
last_space_station = -1
for i in range(0,len(cities_with_space_station)):
    longest_chain.append(len(range(last_space_station+1, cities_with_space_station[i])))


    if i == len(cities_with_space_station) -1:
        #longest_chain.append(len(range(last_space_station+1, cities_with_space_station[i])))
        longest_chain.append(len(range(cities_with_space_station[i]+1, n)))

    last_space_station = cities_with_space_station[i]

#print(longest_chain)


max_val = max(longest_chain)



if max_val == longest_chain[-1] or max_val == longest_chain[0]:
    print(max_val)
elif (max_val + 1)//2 < longest_chain[-1] or (max_val + 1)//2 < longest_chain[0]:
    print(max([longest_chain[-1], longest_chain[0]]))
else:
    print((max_val + 1)//2)

    

