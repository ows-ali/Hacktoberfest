def getCount(inputStr):
    num_vowels = 0

    num_vowels += inputStr.lower().count("a")
    num_vowels += inputStr.lower().count("e")
    num_vowels += inputStr.lower().count("i")
    num_vowels += inputStr.lower().count("o")
    num_vowels += inputStr.lower().count("u")

    return num_vowels

def getCountBetterSolution(inputStr):
    return sum(1 for let in inputStr if let in "aeiouAEIOU")