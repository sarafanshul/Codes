n , k = map(int , input().split())
if n%2 == 0 and n != 1:
	# n is of odd length
	# n//2 odds + n//2 evens
	# if k < n
	if k <= n//2 : # odd region
		print(k*2 - 1)
	else:
		print((k-n//2)*2)
else:
	# n is of even length
	# print('e')
	if k <= n//2 + 1: # odd region
		print(k*2 -1)
	else:
		print(((k-n//2)-1)*2)
