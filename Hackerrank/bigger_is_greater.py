

def find_next_bigger_word(word):
    # find the logest non increasing suffix
    word_arr = list(word)
    word_cnt = len(word_arr)
    suffix_start_index = 0
    for i in range(word_cnt-1, -1 , -1):
        if i == 0 or word_arr[i] > word_arr[i-1]:
            suffix_start_index = i
            break
    #print("logest non increasing suffix: ", word_arr[suffix_start_index: word_cnt])
    # Identify the pivot
    if suffix_start_index == 0:
        return "no answer"
    pivot_el = word_arr[suffix_start_index - 1]

   # print("pivotal element: ", pivot_el)
    # find rightmost successor of pivot element
    for i in range(word_cnt-1,suffix_start_index -1, -1 ):
        #print(pivot_el, word_arr[i])
        if pivot_el < word_arr[i]:
            word_arr[ i ], word_arr[suffix_start_index - 1] = pivot_el, word_arr[ i ]
            break

    #print("swapped with righmost successor: ", word_arr)

    # reverse suffix
    suffix_str = word_arr[suffix_start_index: word_cnt]
    suffix_str = suffix_str[::-1]
    #word_arr[suffix_start_index: word_cnt] = word_arr[suffix_start_index: word_cnt].reverse()

    #print("reversed suffix: ",word_arr[0: suffix_start_index] + suffix_str )
    return (''.join(word_arr[0: suffix_start_index] + suffix_str))

     

n = int(input())

for i in range(0, n):
    print(find_next_bigger_word(input()))