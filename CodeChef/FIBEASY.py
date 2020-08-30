
for _ in range(int(input())):
	num = int(input())
	
	n = 8   # (2^3)
	powr = 3

	if num <= 3:
		if num == 1: print(0)
		else: print(1)
	
	else:
		while True:
			if num < n : break
			n = n*2
			powr += 1

		if powr%4 == 0:   print(3)
		elif powr%4 == 3: print(2)
		elif powr%4 == 2: print(9)
		elif powr%4 == 1: print(0)
