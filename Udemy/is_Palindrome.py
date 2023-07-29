def isPalindrome(text):
    if(text==text[::-1]):
        print("text is palindrome")
    else:
        print("text is not a palindrome")
isPalindrome(input("enter the text : "))