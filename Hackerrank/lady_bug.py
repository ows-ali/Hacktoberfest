games = int(input())

def check_if_bug_is_happy(bug_colors,n):
    bug_colors_arr = list(bug_colors)

    bug_color_ont_dict = dict()
    empty_spaces = 0
    #is_all_bug_happy = dict()
    unhappy_bug_count = 0
    #unhappy_bug_array = []
    for i in range(0,n):
        if bug_colors_arr[i] != '_':
            if bug_color_ont_dict.get(bug_colors_arr[i]) != None:
                bug_color_ont_dict[bug_colors_arr[i]] += 1
            else:
                bug_color_ont_dict[bug_colors_arr[i]] = 1
            if i > 0 and i < n-1 and (bug_colors_arr[i] == bug_colors_arr[i-1] or bug_colors_arr[i] == bug_colors_arr[i+1] ):
                continue
                #is_all_bug_happy[bug_colors_arr[i]] = True
            elif i == 0 and i != n-1 and bug_colors_arr[i] == bug_colors_arr[i+1] :
                continue
                #is_all_bug_happy[bug_colors_arr[i]] = True
            elif i == n-1 and i != 0 and bug_colors_arr[i] == bug_colors_arr[i-1] :
                continue
                #is_all_bug_happy[bug_colors_arr[i]] = True
            else:
                unhappy_bug_count+=1
                unhappy_bug_array.append(bug_colors_arr[i])
                #is_all_bug_happy[bug_colors_arr[i]] = False
        else:
            empty_spaces += 1 
   # print(bug_color_ont_dict, unhappy_bug_count)

    can_all_be_happy = True
    for b in bug_color_ont_dict.keys():
        if (bug_color_ont_dict[b] % 2 == 0 or bug_color_ont_dict[b] % 3 == 0):
            continue
        else:
            can_all_be_happy = False
            break

    if unhappy_bug_count == 0:
        print("YES")
    elif can_all_be_happy and unhappy_bug_count !=0 and empty_spaces > 0:
        print("YES")
    else:
        print("NO")




for game in range(0, games):
    n = int(input())
    check_if_bug_is_happy(input(),n)

    