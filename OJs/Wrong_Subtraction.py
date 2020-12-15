N , n = map(int , input().split())
for i in range(n):
	if str(N).endswith('0'):
		N //= 10
	else:
		N -= 1
print(N)  