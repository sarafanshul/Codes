
for case in range(int(input())):
	n = int(input())
	*a , = map(int , input().split())

	x = a[n-1] # last dig as low
	count = 0
	for i in range(n-2, -1, -1):
		if x < a[i]:
			count += 1
		else:
			x = min(x ,a[i])

	print(count)
	
