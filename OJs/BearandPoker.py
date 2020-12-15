n = int(input())
*a , = map(int , input().split())

# mx = float(max(m))

# flag = 1

# for i in m:
# 	if i*2 == mx or i*3 == mx or i == mx:
# 		continue
# 	else:
# 		flag = 0

# if flag : print('YES')
# else: print('NO')
for i in range(n):
	while (a[i] % 2 == 0): a[i] /= 2
	while (a[i] % 3 == 0): a[i] /= 3

flag = 0
for i in range(n):
	if a[i] != a[0]:
		flag = 1
		print("NO")
		break

if not flag: print('YES')