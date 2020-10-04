from math import log2

def consecutive_ducks(n):
    return not log2(n).is_integer()