# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A ,B ,C = map(int , input().split())

# 	ans = 0

# 	for a in range(2,A+1):
# 		aot = 0
# 		for b in range(1,B+1):
# 			bot = 0
# 			for c in range(1,C+1):
# 				if (b*b) - (a-1)*(c-1) < 0:
# 					ans += 1
# 					aot += 1
# 					bot += 1
# 					print(a,b,c)
# 					# print(a , b)

# 			# print('---b---' ,b , "*_^*_^*"*5, bot ,'a , b = ' ,a,b)
# 			print('= = =')
# 		print('----a----' , a , '-!^-^!-'*5 , aot ,'a , b = ' ,a,b)

# 	print(ans%MOD) 


# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A, B, C = map(int, input().split())

# 	ans = 0

# 	for a in range(2, A+1):
# 		aot = 0
# 		for b in range(1, B+1):
# 			# if b > a*5:
# 			# 	break
# 			for c in range(1, C+1):
# 				if (b*b) - (a-1)*(c-1) < 0:
# 					ans += C-c+1
# 					aot += 1
# 					# print(a, b, c)
# 					break
			
# 			if a < 6 and b > a*5:
# 				break
# 			if a < 13 and b > a*4:
# 				break
# 			if a < 25 and b > a*3:
# 				break

# 		# 	print('= = =')
# 		# print('----a----', a, '-!^-^!-'*5, aot, 'a , b = ', a, b , ans)

# 	print(ans % MOD)

# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A, B, C = map(int, input().split())

# 	ans = 0

# 	for a in range(2, A+1):
# 		aot = 0
# 		for b in range(1, B+1):
# 			# if b > a*5:
# 			# 	break

# 			if a < 5 and b > a*5:
# 				break
# 			elif a >= 5 and a < 12 and b > a*4:
# 				break
# 			elif a >= 12 and a < 25 and b > a*3:
# 				break
# 			elif a >= 25 and a < 100 and b > a*2:
# 				break
# 			elif a >= 100 and b > a :
# 				break
				
# 			for c in range(1, C+1):
# 				if (b*b) - (a-1)*(c-1) < 0:
# 					ans += C-c+1
# 					aot += 1
# 					# print(a, b, c)
# 					break

# 		# 	print('= = =')
# 		# print('----a----', a, '-!^-^!-'*5, aot, 'a , b = ', a, b , ans)

# 	print(ans % MOD)


# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A, B, C = map(int, input().split())

# 	ans = 0

# 	for a in range(2, A+1):
# 		# aot = 0
# 		# flag = 1
# 		for b in range(1, B+1):
# 			# if flag: 
# 			# if a < 5 and b > a*5:
# 			# 	break
# 			# elif a >= 5 and a < 12 and b > a*4:
# 			# 	break
# 			# elif a >= 12 and a < 25 and b > a*3:
# 			# 	break
# 			# elif a >= 25 and a < 100 and b > a*2:
# 			# 	break
# 			# elif a >= 100 and b > a:
# 			# 	break

# 			for c in range(1, C+1):
# 				flag = 0
# 				if (b*b) - (a-1)*(c-1) < 0:
# 					ans += C-c+1
# 					# aot += 1
# 					flag = 1
# 					break
# 			if  not flag :
# 				break
# 		# print(a,b,c)

# 	print(ans % MOD)


# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A, B, C = map(int, input().split())

# 	ans = 0

# 	for a in range(2, A+1):

# 		for b in range(1, B+1):

# 			for c in range(1, C+1):
# 				flag = 0
				
# 				if (b*b) - (a-1)*(c-1) < 0:
# 					ans += C-c+1
# 					flag = 1
# 					print(a, b, c, '**'*3,  ans, (a*b*c), (a*b*c)/ans, ans/((a*b*c)))
# 					break

# 			if not flag:
# 				break
# 		print()
# 		print('---'*3, a, b, c, '++'*3, ans, (a*b*c), (a*b*c)/ans, ans/((a*b*c)))
# 		print()

# 	print(ans % MOD)

# from time import time

# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A, B, C = map(int, input().split())
# 	# s = time()

# 	ans = 0

# 	for a in range(2, A+1):

# 		for b in range(1, B+1):

# 			tmp = int( ((b*b)/(a-1)) + 1) + 1
# 			if tmp > C: break
# 			ans += C - tmp + 1

# 		print()
# 		print('---'*3, a, b-1 , ans , (b-1)/a , a/(b-1))
		

# 	print(ans % MOD)
# 	# print(time() - s)

# from math import sqrt
# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A, B, C = map(int, input().split())
# 	# s = time()

# 	ans = 0

# 	for a in range(2, A+1):

# 		# find limit 
# 		lmt = int(sqrt((C-2)*(a-1)))

# 		# summate
# 		K = (lmt)*(lmt+1)*(2*(lmt)+1)/6

# 		fnl = int(K/(a-1))

# 		# ans += lmt*C - fnl + lmt*1 + lmt*2
# 		ans += (lmt)*C - fnl
# 		print(lmt , K , fnl , ans)


# 	print(ans % MOD)
# 	# print(time() - s)


# from math import sqrt
# MOD = int(1e9) + 7

# for _ in range(int(input())):
# 	A, B, C = map(int, input().split())
# 	# s = time()

# 	ans = 0

# 	for a in range(2, A+1):

# 		# find limit
# 		# 1) lmt = int(sqrt((C-2)*(a-1)))
# 		lmt = int(sqrt((C-1)*(a-1)))

# 		# summate
# 		K = ((lmt)*(lmt+1)*(2*(lmt)+1))/6

# 		fnl = int(K/(a-1) + lmt*2)

# 		# tmp = int( ((b*b)/(a-1)) + 1) + 1
# # 		ans += C - tmp + 1
# 		# ans += lmt*C - fnl + lmt*1 + lmt*2
		
# 		ans += (lmt)*C - fnl + lmt
# 		# print(lmt, K, fnl, ans, (lmt)*C - fnl + lmt)

# 	print(ans % MOD)
# 	# print(time() - s)

from math import sqrt , ceil
MOD = int(1e9) + 7

for _ in range(int(input())):
	A, B, C = map(int, input().split())
	# s = time()

	ans = 0

	for a in range(2, A+1):

		# find limit
		# 1) lmt = int(sqrt((C-2)*(a-1)))
		lmt = int(sqrt((C-1)*(a-1)))

		# summate
		K = ((lmt)*(lmt+1)*(2*(lmt)+1))/6

		fnl = int(K/(a-1)) + lmt*2

		# tmp = int( ((b*b)/(a-1)) + 1) + 1
		# ans += C - tmp + 1
		# ans += lmt*C - fnl + lmt*1 + lmt*2

		ans += (lmt)*C - (fnl) + lmt 
		print(lmt, K, fnl, ans)

	print(ans % MOD)
	# print(time() - s)
