# using * as an Argument:
# Argument Unpacking
# We can use * as an argument to a function to 'unpack' values

def sum_all_values(*args):
    total = 0
    for num in args:
        total += num # can't add an int and a ['list'] or (tuple,)
    print(total)

nums = [1, 2, 3, 4, 5, 6, 7]
sum_all_values(*nums) # if you have a list of things that you want to unpack & send to a function NOT expecting a list

# works with tuples too
nums = (4,7,89,3,6,45,24)
sum_all_values(*nums)

# Using ** as an argument
# Dictionary Unpacking 
# unpacks keyword arguments into a dictionary

def display_names(first, second):
    print(f"{first} says hello to {second}")

names = {"first": "Chris", "second": "Kim"}

display_names(first="Charlie", second="Sue") # How to do it manually
display_names(**names)

def add_and_multiply_numbers(a, b, c, **kwargs):
    print(a + b * c)
    print("Other stuff")
    print(kwargs)

data = dict(a=2, b=3, c=4)

# add_and_multiply_numbers(data) # throws a TypeError
add_and_multiply_numbers(**data)

#now add more stuff to dictionary & add **kwargs to function
def add_and_multiply_numbers(a, b, c, **kwargs):
    print(a + b * c)
    print("Other stuff")
    print(kwargs)

data = dict(a=2, b=3, c=4, d=55, name="Chris")
add_and_multiply_numbers(**data)

#can still pass in more stuff after a **arg: 
add_and_multiply_numbers(**data, cat="Binky")