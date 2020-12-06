# TLE + pass(sub(1))

from collections import deque

for i in range(int(input())):
	n , m = map(int , input().split())

	arr = deque([[i+1 , j+1] for j in range(m)] for i in range(n))
	
	arr1 = deque()
	for i in arr:
		arr1.extend(i)

	arrr = deque([[j+1 , i+1] for j in range(n)] for i in range(m))
	
	arr2 = deque()
	for i in arrr:
		arr2.extend(i)


	print(n*m , end = ' ')
	
	for k in range(2 , n*m+1):
		out = deque()
		rest = k
		count = 0
		c = 0
		while c < n*m:
			out.append(arr1[c])
			out.append(arr2[c])
			c += k

		temp = deque()
		for i in out:
			if i in temp:
				pass
			else:
				temp.append(i)
				count += 1

		print(count , end = ' ')



# # # # # #
# arr = [[[i , j] for j in range(3)] for i in range(3)]

# print(arr)

# # arr1 = [0 for i in range(9)] # n*m
# arr1 = []
# for i in arr:
# 	arr1.extend(i)

# print(arr1)


# arrr = [[[j , i] for j in range(3)] for i in range(3)]

# arr2 = []
# for i in arrr:
# 	arr2.extend(i)

# print(arr2)

# # kill perspective
# # k(0) is always m*n
# # k(1) are evens(dead)
# # k(n) i kill n rest -> for 2 - n:


# time supported :)
# ~ 0.0468747615814209 for 7500 itrations
# # time ->
# from time import time
# s=time()
# arr = [[[i , j] for j in range(3)] for i in range(2500)]

# arr1 = []
# for i in arr:
# 	arr1.extend(i)
# print(arr1[10:])

# print(time()-s)



# for i in range(int(input())):
# 	n , m = map(int , input().split())

# 	arr = [[[i+1 , j+1] for j in range(m)] for i in range(n)]

# 	arr1 = []
# 	for i in arr:
# 		arr1.extend(i)

# 	# print(arr1)

# 	arrr = [[[j+1 , i+1] for j in range(n)] for i in range(m)]

# 	arr2 = []
# 	for i in arrr:
# 		arr2.extend(i)

# 	# print(arr2)

# 	print(n*m , end = ' ')
# 	# print()
	
# 	for k in range(2 , n*m+1):
# 		out = []
# 		rest = k
# 		count = 0
# 		# for a in range(n*m):
# 		a = b = 0
# 		while a < n*m:
# 			# print(arr1[a])
# 			out.append(arr1[a])
# 			a += k

# 		while b < n*m:
# 			out.append(arr2[b])
# 			b += k

# 		# print(out)
# 		# alter count here 
# 		temp = []
# 		for i in out:
# 			if i in temp:
# 				pass
# 			else:
# 				temp.append(i)
# 				count += 1

# 		print(count , end = ' ')
# 		# print()

# from collections import deque

# for i in range(int(input())):
# 	n , m = map(int , input().split())

# 	arr = deque([[i+1 , j+1] for j in range(m)] for i in range(n))
	
# 	arr1 = deque()
# 	for i in arr:
# 		arr1.extend(i)

# 	arrr = deque([[j+1 , i+1] for j in range(n)] for i in range(m))
	
# 	arr2 = deque()
# 	for i in arrr:
# 		arr2.extend(i)	

# 	print(n*m , end = ' ')
	
# 	for k in range(2 , n*m+1):
# 		out = deque()
# 		rest = k
# 		count = 0
# 		c = 0
# 		while c < n*m:
# 			out.append(arr1[c])
# 			out.append(arr2[c])
# 			c += k

# 		temp = deque()
# 		for i in out:
# 			if i in temp:
# 				pass
# 			else:
# 				temp.append(i)
# 				count += 1

# 		print(count , end = ' ')