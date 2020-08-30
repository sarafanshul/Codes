n , m , a , b = map(int , input().split())
if n < m :
	if b < a*n:
		print(b)
	else: 
		print(n*a)
elif b/m < a:
	# special is cheaper
	if ((n//m)*b) + ((n%m)*a) > ((n//m)*b) + b:
		print(((n//m)*b) + b)
	else:
		print(((n//m)*b) + ((n%m)*a))
else:
	print(n*a)