for l in range(int(input())):
    n = int(input())
    
    skills = list(map(int, input().split()))
    
    min = abs(skills[0] - skills[1])
    
    for i in range(n-1):
        for k in range(i+1, n):
            diff = abs(skills[i] - skills[k])
            if diff < min:
                min = diff
    print(min)