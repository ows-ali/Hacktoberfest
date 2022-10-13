if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    arr1 = [*set(arr)]
    min = max(arr1)
    arr1.remove(min)
    min = max(arr1)
    print(min)
        
