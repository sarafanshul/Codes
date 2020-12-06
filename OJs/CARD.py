
for case in range(int(input())):
	cards = list(map(int , input()))
	if cards.count(1) % 2 == 1: print('WIN')
	else: print('LOSE')
		