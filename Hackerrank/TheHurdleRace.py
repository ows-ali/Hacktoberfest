
#Practice > Algorithms > Implementation > The Hurdle Race

def hurdleRace(k, height):
    dose = 0 #Final dose required
    max = height[0] #maximum height of the hurdles
    for i in height:
        if i > max:
            max = i
    if k < max:
        dose = max - k
    else:
        dose = 0
    return dose

'''
For testing:
n = 5 #no. of hurdles
k = 1 #height he can jump
h = [1, 2, 3, 3, 2]
print(hurdleRace(k,h))
'''
