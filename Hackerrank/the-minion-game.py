def is_vowel(character):
    # Based on the assumption where character will always be uppercase
    return True if character in ['A', 'E', 'I', 'O', 'U'] else False

def minion_game(string):
    stuart_score = 0
    kevin_score = 0
    for idx, c in enumerate(string):
        if is_vowel(c):
            kevin_score += (len(string) - idx)
        else:
            stuart_score += (len(string) - idx)
    if stuart_score > kevin_score:
        print(f"Stuart {stuart_score}")
    elif stuart_memo < kevin_score:
        print(f"Kevin {kevin_score}")
    else:
        print("Draw")

if __name__ == '__main__':
