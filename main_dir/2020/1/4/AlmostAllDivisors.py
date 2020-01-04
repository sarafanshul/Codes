# for case in range(int(input())):
# 	n = int(input())
# 	*div , = map(int , input().split())
# 	div.sort()

# 	if n == 1:
# 		print(div[0]**div[0])
# 	elif n == 2:
# 		print(div[0]*div[1])
# 	elif n > 2:
# 		if div[0]*div[-1] == div[1]*div[-2]:
# 			print(div[0]*div[-1])
# 		else:
# 			print(-1)

for case in range(int(input())):
	n = int(input())
	*a , = map(int , input().split())

	# a.sort()
	s = dict()
	# mm = a[0]*a[-1]
	mm = min(a)*max(a)
	for x in range(2 , mm+1):
		if mm%x == 0:
			s[x] = int(mm/x)

	flag = 1
	# print(s)
	if len(s)-1 == n:

		for i in range(n-1):
			# if s[a[i]] != s[mm]:
			# 	continue
			if s[a[i]] * a[i] == mm:
				continue
			flag = 0
			break
	else:
		flag = 0

	if flag:
		print(mm)
	else:
		print(-1)