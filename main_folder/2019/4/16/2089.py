n = int(input())
base = 1
st = []
if(n == 0):
	print (0)
else:
	while(n):
		if(n % 2):
			st.append(1)
			n -= base
		else:
			st.append(0)
		base *= (-1)
		n /= 2
	while(len(st)):
		print (st[len(st)-1],end="")
		st.pop()
