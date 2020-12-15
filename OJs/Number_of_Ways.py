n = int(input())
*arr , = map(int , input().split())

prefix_arr = [0 for i in range(n)]
prefix_arr[0] = arr[0]

for i in range(1 ,n):
	prefix_arr[i] = arr[i] + prefix_arr[i-1]

ans = fac = 0

# print(*prefix_arr)

for i in range(n-1):
	if prefix_arr[i]*3 == prefix_arr[n-1]*2:
		ans += fac
		# print('a')
		
	if prefix_arr[i]*3 == prefix_arr[n-1]:
		# print('f')
		fac += 1
		

print(ans)

