# On every instance of m it checks if it is present in the set of cats
# Basically, it checks if any cat is not fed twice more than any other cat
# Solution id -26886073

def FILL_SET(set_m):
    set_new_m = {}
    set_new_m = { _+1 for _ in range(set_m)}
    return set_new_m

def isItFair(n, m, cats_feed):
    cat_set = FILL_SET(n)
    for j in cats_feed:
        if len(cat_set) is 0 :
            cat_set = FILL_SET(n)

        if {j}.issubset(cat_set):
            cat_set.remove(j)
        else:
            return "NO"
    return "YES"




if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        nrm = list(map(int, input().split(" ")))

        n_cats = nrm[0]            

        m_bowls = nrm[1]

        cat_food = list(map(int, input().split(" ")))
    
        result = isItFair(n_cats, m_bowls, cat_food)

        print(str(result))

    
