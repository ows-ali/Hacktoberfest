n = input()
s = raw_input()
 
level = 0
valleys = 0
for direction in s:
    if direction == "U":
        level += 1
        if level == 0:
            valleys += 1
    else:
        level -= 1
         
print valleys