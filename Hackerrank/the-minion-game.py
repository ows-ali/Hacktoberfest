def minion_game(string):
    vowels = 'AEIOU'
    stuart = 0
    kevin = 0
    n = len(string)
    for i in range(n):
        if s[i] in vowels:
            kevin += n-i
        else:
            stuart += n-i
    
    if stuart > kevin:
        print("Stuart {}".format(stuart))
    elif stuart < kevin:
        print("Kevin {}".format(kevin))
    else:
        print("Draw")