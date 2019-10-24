# Problem link: https://www.hackerrank.com/challenges/s10-basic-statistics/problem

def get_mean(size, numbers):
    """
    Gets the average for N elements in an array
    Input:
    - size(int): number of elements
    - number(array[float]): list of element to calculate the mean

    Returns:
    - res(float): mean of the elements
    """
    sum_nums = 0
    for element in numbers:
        sum_nums += int(element)
    
    res = round(sum_nums/size,1)

    return  res

def get_median(size, numbers):
    """
    Gets the value in the middle for N elements in an array
    Input:
    - size(int): number of elements
    - number(array[float]): list of element to calculate the median

    Returns:
    - res(float): median of the elements
    """

    middle = size/2

    if (middle).is_integer():
        median = get_mean(2,[numbers[int(middle-1)],numbers[int(middle)]])
    else:
        median = numbers[int(middle)] 
    
    return median

def get_mode(size, numbers):
    """
    Gets the mode for N elements in an array
    Input:
    - number(array[float]): list of element to calculate the mode

    Returns:
    - res(float): mode of the elements
    """
    mode = -1
    count = 0
    count_max = 0
    prev = numbers[0]

    for element in numbers:
        if element == prev:
                count += 1
                prev = element
                mode = element
                if count > count_max:
                    count_max = count
                    mode = element
        else:
            count = 1
    
    return mode


size = int(input())
numbers = [int(i) for i in input().split(' ')]
numbers.sort()

print(get_mean(size,numbers))
print(get_median(size,numbers))
print(get_mode(size, numbers))
