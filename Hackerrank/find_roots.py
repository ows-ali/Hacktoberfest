

"""
How it works:
	Thing is simple first we determine the variable in equation;
	Then we iterate through given range by user or default range;
	For each iteration we replace the variables in equation to the number;
	At last we return the roots found;
"""

from string import ascii_letters


def find_variable(string):
	splitted = string.split()
	for i in splitted:
		if (i in ascii_letters):
			return i
		else: continue
	return None

# Input format for function:
# "z ** 2 + 97 * z + (-4)"

def find_roots(S, rng = [-10000, 10000]):
	res = []
	for v in range(rng[0], rng[1]):
		try:
			test_case = S.replace(find_variable(S), str(v))
		except Exception as e:
			print(e)
			return ""
		if (eval(test_case) == 0):
			res.append(v)
		else:
			continue

	if (len(res) == 0):
		return None
	return res

#testing

"""
test_str = "x ** 2 + 5 * x - 6"
result = find_roots(test_str, [-10, -2])
for i in result:
	print("Root of the equation is {}".format(i))
"""
