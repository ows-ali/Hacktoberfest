#https://www.codechef.com/problems/MSNSADM1

def prog():
	test = input('')
	test = int(test)
	values = []
	for case in range(test):
		players = int(input(''))
		points = []
		goals = input('').split()
		fouls = input('').split()
		for player in range(players):
			score = (20*int(goals[player])) - (10*int(fouls[player]))
			points.append(score if score>0 else 0)
		values.append(str(max(points)))
	print(' '.join(values))
prog()