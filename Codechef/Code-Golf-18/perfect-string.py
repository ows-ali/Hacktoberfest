# https://www.codechef.com/COLF2018/problems/APR104

inp = raw_input().strip()

c_flag = 0
another_flag = 0
vow = ('a', 'e', 'i', 'o', 'u')

if inp[0] in vow:
    print False
else:
    for index, item in enumerate(inp):
        if item not in vow and c_flag == 0:
            c_flag = 1
        elif item in vow and c_flag == 1:
            try:
                if inp[index + 1] not in vow:
                    c_flag = 0
                continue
            except IndexError:
                break
        elif item not in vow and c_flag == 1:
            print False
            another_flag = 1
            break
        elif c_flag == 0 and item in vow:
            print False
            another_flag = 1
            break

    if another_flag == 0:
        print True
