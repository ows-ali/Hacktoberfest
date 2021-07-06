# works with custom input, codechef IDE has problem with taking inputs for python 3^
# just count the number of odd numbers ahead of every even number in the list

def countEO(n_a, size):
    even = []
    c = 0
    for itr in range(size):
        if n_a[itr]%2 is 0 :
            even.append(itr)
    for k in range(len(even)):
        c += size - (even[k] + 1) - (len(even) - k -1)
    return c
    


if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nrm = int(input())

        num_array = list(map(int, input().split(" ")))
    
        result = countEO(num_array, nrm)

        print(str(result))
