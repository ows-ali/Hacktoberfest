

def linearSort(array):
    for i in array:
        j = 0
        temp = array[i]
        while  j < len(array):
            if array[j] < array[i]:
                j += 1
            else:
                array[i] = array[j]
                array[j] = temp

randomNumbers = [0, 1, 45, 4, 8, 9, 4481, 0]

linearSort(randomNumbers)

