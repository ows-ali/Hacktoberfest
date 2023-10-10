def minion_game(string):
    vowels = ["A", "E", "I", "U", "O", "a", "e", "i", "u", "o"]
    kevin_score = 0
    stuart_score = 0
    for i in range(len(string)):
        if string[i] in vowels:
            score = len(string) - i
            kevin_score += score
        else:
            score = len(string) - i
            stuart_score += score
    
    if kevin_score > stuart_score:
        print("Kevin", kevin_score)
    elif stuart_score > kevin_score:
        print("Stuart", stuart_score)
    else:
        print("Draw")

