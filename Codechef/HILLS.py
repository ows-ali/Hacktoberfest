

def rightmostHill(arr, U, D):
    flag = 0
    # print(arr)
    for itr in range(len(arr)-1):
        # print('itr', itr)
        if arr[itr+1]-arr[itr] > 0 and arr[itr+1]-arr[itr] > U:
            return itr+1
        if arr[itr+1]-arr[itr] < 0 and abs(arr[itr+1]-arr[itr]) > D:
            if flag == 1:
                return itr+1
            else:
                flag = 1
    return itr+2 

if __name__=='__main__':
    t =int(input())

    for _ in range(t):
        line = input().split(" ")
        N = int(line[0])
        U = int(line[1])
        D = int(line[2])

        arr = list(map(int, input().split(" ")))

        result = rightmostHill(arr, U, D, )

        print(result)