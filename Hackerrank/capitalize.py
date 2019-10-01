
# Capialize every first letter.
import string 
def solve(s):
    n=""
    k=s.split(' ')
    for i in range(len(k)):
        n+=k[i].capitalize()+" "
    return n
    
