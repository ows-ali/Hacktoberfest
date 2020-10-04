def get_sum_of_digits(num):
    numStr = str(num)
    sum = 0

    for x in numStr:
        sum += int(x)

    return sum

def better(num):
    return sum(map(int, str(int(num))))