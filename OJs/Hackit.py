
for i in range(int(input())):
	pattern = input()
	
	ln = len(pattern)
	arr = [0 for i in range(ln+1)]
	lst_ch = c = l = r = 0
	arr[0] = 1

	while c < ln:
		
		if pattern[c] == '+':
			arr[c+1] = arr[lst_ch] + 1
			lst_ch = c+1

		else:
			arr[c+1] = arr[c]
			i = c
			while i >= lst_ch:
				arr[i] = arr[i] + 1
				i -= 1
		c+=1

	print(*arr)
