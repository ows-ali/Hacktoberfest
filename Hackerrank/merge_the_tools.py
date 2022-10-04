def merge_the_tools(string, k):
    sub = int(len(string)/k)
    lst = list(string)
    for i in range(0, len(string), k):
        if i+k <= len(string):
            print(''.join(list(dict.fromkeys(lst[i:i+k]))))
            