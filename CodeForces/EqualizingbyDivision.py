# # n , com = map(int , input().split())
# # *a , = map(int , input().split())

# # test = [0 for i in range(n)]
# # for i in range(n):
# # 	test[i] = a[i]%2

# # print('mod2' , test)

# # test1 = [0 for i in range(n)]
# # m = min(a)

# # for i in range(n):
# # 	test[i] = a[i]-m

# # print('-min' , test1)

# # # com
# # a.sort()

# # print('digits for op' , a[:com+1])

# # a1 = a[:com+1]

# # test3 = []
# # for i in a1:
# # 	if i % 2 == 0:
# # 		test3.append(i)

# # print('even dig for op' , test3)

# # test4 = list(set(test3.copy()))

# # test6 = []

# # # print(n)
# # for i in test4:
# # 	# print(a.index(i))
# # 	pos = n - a.index(i) - 1
# # 	# print(pos)
# # 	if pos >= com:
# # 		test6.append(i)

# # print('possible' , test6)

# # test7 = []
# # for i in list(set(a)):
# # 	test7.append([i , a.count(i)])
# # 	if a.count(i) == com:
# # 		print('found' , i , 'else')

# # print(test7)
# # test7.sort(key = lambda t: t[1] ,reverse = True)

# # print(test7)

# # test6 = test6[::-1]

# # maxcntl = [t[0] for t in test7[:com+1]]
# # print(test6)
# # print(maxcntl)
# # for i in test6:
# # 	if i in maxcntl:
# # 		print('now===' , i)





# # # # # # # # # # # # # # # # # # # # # # # # # # #

# # n , com = map(int , input().split())
# # *a , = map(int , input().split())

# # flag = 0
# # test7 = []

# # for i in list(set(a)):
# # 	test7.append([i , a.count(i)])
# # 	if a.count(i) == com:
# # 		# print('found' , i , 'else')
# # 		flag = 1

# # if flag:
# # 	print(0)
# # else:
# # 	# a.sort()
# # 	# print('digits for op' , a[:com+1])
# # 	# a1 = a[:com+1]

# # 	a.sort()
# # 	a1 = a[:com+1]

# # 	test3 = []
# # 	for i in a1:
# # 		if i % 2 == 0:
# # 			test3.append(i)
# # 	# print('even dig for op' , test3)

# # 	test4 = list(set(test3.copy()))

# # 	test6 = []

# # 	# print(n)
# # 	for i in test4:
# # 		# print(a.index(i))
# # 		pos = n - a.index(i) - 1
# # 		# print(pos)
# # 		if pos >= com:
# # 			test6.append(i)

# # 	# print('possible' , test6)

# # 	test6 = test6[::-1]

# # 	maxcntl = [t[0] for t in test7[:com+1]]
# # 	# print(test6)
# # 	# print(maxcntl)
# # 	for i in test6:
# # 		if i in maxcntl:
# # 			# print('now===' , i)
# # 			element = i

# # 	print('e' , element)




# n , com = map(int , input().split())
# *a , = map(int , input().split())

# flag = 0
# test7 = []

# for i in list(set(a)):
# 	test7.append([i , a.count(i)])
# 	if a.count(i) == com:
# 		flag = 1

# if flag:
# 	print(0)
# else:
# 	a.sort()
# 	a1 = a[:com+1]
# 	test3 = []

# 	for i in a1:
# 		if i % 2 == 0:
# 			test3.append(i)

# 	test4 = list(set(test3.copy()))
# 	test6 = []

# 	for i in test4:
# 		pos = n - a.index(i) - 1
# 		if pos >= com:
# 			test6.append(i)

# 	test6 = test6[::-1]
# 	maxcntl = [t[0] for t in test7[:com+1]]

# 	for i in test6:
# 		if i in maxcntl:
# 			element = i

# 	# print('e' , element)
# 	# element is the base element for operttions

# 	# ppossible operations = higher elements than e
	
# 	cntbase = a.count(element)
# 	poss = []

# 	for i in a:
# 		if i > a+1:
# 			poss.append(i)

# 	if len(poss) + cntbase < com:
# 		print("error manage these")
	

vals = [[] for i in range(200*1000 + 11)]
ans = 10**19+7

n , k = map(int , input().split())
*a , = map(int , input().split())

for i in range(n):
	x = a[i]
	cur = 0
	while x > 0:
		vals[x].append(cur)
		x //= 2
		cur += 1 #check here

for i in range(200*1000):
	new = vals[i]
	new.sort()
	if len(new) < k: 
		continue

	ans = min(ans , sum(new[:k]))

print(ans)
