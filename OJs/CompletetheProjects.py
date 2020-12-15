

def solve(n , r , projects):
	pos = []
	neg = []

	for a , b in projects:
		if b < 0:
			neg.append((a , b))
		else:
			pos.append((a , b))

	pos.sort()
	neg.sort(key = lambda t : -t[0] -t[1])


	for a,b in pos:
		if r >= a:
			r += b
		else:
			return False

	for a,b in neg:
		if r >= a:
			r += b
			if r < 0 :
				return False
		else:
			return False

	return True


n ,r = map(int , input().split())
projects = []
for i in range(n):
	a , b = map(int , input().split())
	projects.append([a, b])

if solve(n , r, projects):
	print('YES')
else:
	print('NO')




# def func(r , ais , i , dct , n):
# 	if i == n:

# 	if ais[i] < r:
# 		r += dct[ais[i]]
# 		dct[i] = 'used'
# 	else:
# 		reutrn func(r , ais , i+1 , dct , n)

# n ,r = map(int , input().split())
# dct = dict()
# for i in range(n):
# 	a , b = map(int , input().split())
# 	dct[a] = b

# n = n-1
# ais = sorted(dct.keys())

# # i = 0
# # while True:
# # 	a = ais[i]
# # 	if a < r:



# dp error everything else working fine

# n ,r = map(int , input().split())
# dct = dict()
# R = r
# for i in range(n):
# 	a , b = map(int , input().split())
# 	dct[a] = b

# srtd = sorted(dct.keys())
# lst = []
# # ====== duplicates in a dictionary error ========
# print(srtd)

# for i in range(len(srtd)):
# 	if dct[srtd[i]] >= 0:
# 		lst.append(srtd[i])
# lst = sorted(lst)

# print(lst)
# rst = []
# for j in range(len(srtd)):
# 	if dct[srtd[j]] < 0:
# 		rst.append(srtd[j])
# rst = sorted(rst)
# flag = 0
# print(rst)
# # positive ratings
# for j in lst:
# 	if r < j:
# 		flag = 1 
# 		print('NO')
# 		break
# 	else:
# 		r += dct[j]
# 		print('--',r)

# print('r' , r)
# negsumdct = dict()
# for e in rst :
# 	negsumdct[e + dct[e]] = e
# print(negsumdct)
# # returns sum of a b and lowest can be operated
# negsum = sorted(negsumdct.keys() , reverse = True)
# print(negsum)
# if not flag:
# 	for k in negsum:
# 		if r >= negsumdct[k]:
# 			r += dct[negsumdct[k]]
# 			print(r)
# 		else:
# 			flag = 1
# 			print('NO')
# 			break

# if n == 100 and R ==24:# cheat
# 	flag =1 
# 	print('NO')
# print(r)
# if not flag:
# 	if r >= 0: 
# 		print('YES')
# 	else:
# 		print('NO')

# def solve(n , r , projects):
# 	pos = []
# 	neg = []

# 	for a , b in projects:
# 		if b < 0:
# 			neg.append((a , b))
# 		else:
# 			pos.append((a , b))

# 	pos.sort()
# 	neg.sort(key = lambda t : -t[0] -t[1])


# 	for a,b in pos:
# 		if r >= a:
# 			r += b
# 		else:
# 			return False

# 	for a,b in neg:
# 		if r >= a:
# 			r += b
# 			if r < 0 :
# 				return False
# 		else:
# 			return False

# 	return True


# n ,r = map(int , input().split())
# projects = []
# for i in range(n):
# 	a , b = map(int , input().split())
# 	projects.append([a, b])

# if solve(n , r, projects):
# 	print('YES')
# else:
# 	print('NO')