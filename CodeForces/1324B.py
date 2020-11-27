for _ in range(int(input())):
	s= input()
	print("01"*len(s) if (len(set(s)) == 2) else s)