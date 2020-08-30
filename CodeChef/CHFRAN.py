def upper_bound(arr , x):
	l , h = 0 ,len(arr) # not len(arr) - 1

	while l < h:
		mid = (l+h)//2
		if x >= arr[mid]: l = mid +1
		else: h = mid
	return l

def main():
	for t in range(int(input())):
		n = int(input())
		XS = [0 for i in range(n)]
		YS = [0 for i in range(n)]

		for i in range(n):
			a ,b = map(int , input().split())
			XS[i] = a
			YS[i] = b

		XS.sort()
		YS.sort()
		res  ,i = n ,0

		while i < n:
			it = i
			while it < n and YS[it] == YS[i]: it += 1
			idx = upper_bound(XS ,YS[i]) # idk if MAX is neccessary
			if it < n and idx < n: res = min(res ,idx - it)
			i = it

		print(res if res != n else -1)

if __name__ == '__main__':
	main()
# from collections import defaultdict

# for _ in range(int(input())):
# 	N = int(input())
# 	start = []
# 	end = []
# 	arr = []
# 	for i in range(N):
# 		x , y = map(int , input().split())
# 		# start.append(x)
# 		# end.append(y)
# 		arr.append([x , y])
# 	arr.sort(key = lambda a : a[0])

# 	for el in arr:
# 		start.append(el[0])
# 		end.append(el[-1])
	
# 	dlt = 0
# 	aqred = 0
# 	dct = defaultdict(lambda : 0 )
# 	idk_start = []
# 	idk_end = []

# 	for i in range(N):
# 		if dct[start[i]] > 0:
# 			idk_start.append(start[i])
# 		if dct[end[i]] > 0:
# 			idk_end.append(end[i])

# 		dct[start[i]] += 1
# 		dct[end[i]] += 1
# 	print(idk_start , idk_end  , sep = '\n')



# class Grp_Nodes(object):
# 	def __init__(self ,val ,is_start):
# 		self.val = val
# 		self.is_start = is_start

# 	# def __sort__

# nodes = [0 for _ in range(200001)]
# arr2 = [[100000000,100] for _ in range(200001)]

# for _ in range(int(input())):
# 	N = int(input())
# 	# arr = [[0 ,0] for _ in range(N)]
	
# 	for i in range(N):
# 		start , end = map(int , input().split())
# 		# nodes[i*2] = Grp_Nodes(start ,1)
# 		# nodes[i*2+1] = Grp_Nodes(end ,0)

# 		# arr[i*2][0] , arr[i][1] = map(int , input().split())
# 		arr2[i*2][0] = start
# 		arr2[i*2][1] = 1
# 		arr2[i*2+1][0] = end
# 		arr2[i*2+1][1] = 0

# 	arr2.sort(key = lambda ar : ar[0] - ar[1])
# 	# arr3 = []
# 	# for elem in arr2:
# 	# 	if elem[0] != -1 and elem[1] != -1:
# 	# 		arr3.append(elem)

# 	# arr2 = arr3
# 	# arr.sort(key = lambda lst: lst[0] )

# 	# for start ,end in arr:
# 	# 	# start , end = map(int , input().split())
# 	# 	nodes[i*2] = Grp_Nodes(start ,True)
# 	# 	nodes[i*2+1] = Grp_Nodes(end ,False)

# 	# try: # not a loop so one error = game over

# 	# 	nodes.sort(key = lambda val : val.val + val.is_start)
# 	# 	print(nodes)
# 	# 	# nodes.sort(key = custSORT(val))
# 	# except : pass

# 	ans = 100000000
# 	current_active = 1
# 	remaining = N - 1
# 	covered = 0

# 	# for i in range(1 ,2*N):
# 	for i in range(1 ,2*N):
# 		# try:
# 		# 	if nodes[i].val != nodes[i-1].val:
# 		# 		if covered > 0 and remaining > 0:
# 		# 			if current_active < ans:
# 		# 				ans = current_active
# 		# 	if ans == 0:
# 		# 		break

# 		# 	if nodes[i].is_start:
# 		# 		remaining -= 1
# 		# 		current_active += 1
# 		# 	else:
# 		# 		current_active -= 1
# 		# 		covered += 1
# 		# except AttributeError: pass
# 		if arr2[i][0] != arr2[i-1][0]:
# 			if covered > 0 and remaining > 0:
# 				if current_active < ans:
# 					ans = current_active

# 		if ans == 0:
# 			break

# 		if arr2[i][1]:
# 			remaining -= 1
# 			current_active += 1
# 		else:
# 			current_active -= 1
# 			covered += 1

# 	if ans == 100000000:
# 		ans = -1

# 	print(ans)
	



# for _ in range(int(input())):
# 	N = int(input())
# 	arr2 = [[100000000,-1] for _ in range(200001)]
	
# 	for i in range(N):
# 		start , end = map(int , input().split())
# 		# nodes[i*2] = Grp_Nodes(start ,1)
# 		# nodes[i*2+1] = Grp_Nodes(end ,0)

# 		# arr[i*2][0] , arr[i][1] = map(int , input().split())
# 		arr2[i*2][0] = start
# 		arr2[i*2][1] = 1
# 		arr2[i*2+1][0] = end
# 		arr2[i*2+1][1] = 0

# 	arr2.sort(key = lambda ar : ar[0] - ar[1])
# 	ans = 100000000
# 	current_active = 1
# 	remaining = N - 1
# 	covered = 0

# 	for i in range(1 ,2*N):

# 		if arr2[i][0] != arr2[i-1][0]:
# 			if covered > 0 and remaining > 0:
# 				if current_active < ans:
# 					ans = current_active

# 		if ans == 0:
# 			break

# 		if arr2[i][1]:
# 			remaining -= 1
# 			current_active += 1
# 		else:
# 			current_active -= 1
# 			covered += 1

# 	if ans == 100000000:
# 		ans = -1
#	print(ans)

# def CHFRAN():
# 	N = int(input())
# 	arr2 = [[0,0] for i in range(2*N)] # check here
	
# 	for i in range(N):
# 		start , end = map(int , input().split())
# 		arr2[i*2][0] = start
# 		arr2[i*2][1] = True
# 		arr2[i*2+1][0] = end
# 		arr2[i*2+1][1] = False

# 	arr2.sort(key = lambda ar : ar[0] - ar[1])
# 	# print(arr2)
# 	ans = 1000000000 # use 10^8 insted
# 	current_active = 1
# 	remaining = N - 1
# 	covered = 0

# 	for i in range(1 ,N*2): # or N*2+1 ?

# 		if arr2[i][0] != arr2[i-1][0]:
# 			if covered > 0 and remaining > 0:
# 				if current_active < ans:
# 					ans = current_active

# 		if ans == 0:
# 			break

# 		if arr2[i][1]:
# 			remaining -= 1
# 			current_active += 1
# 		else:
# 			current_active -= 1
# 			covered += 1

# 	if ans == 1000000000:
# 		ans = -1

# 	print(ans)

# def main():
# 	# for cases
# 	for _ in range(int(input())):
# 		CHFRAN()

# # basic bitch like dineshC
# if __name__ == '__main__':
# # Python 3.7.3 (v3.7.3:ef4ec6ed12, Mar 25 2019, 21:26:53) [MSC v.1916 32 bit (Intel)] on win32
# 	main()
# 	exit()

# # def upper_bound(a ,b): # binary search for pairs
# def upper_bound(arr , x):
# 	l = 0
# 	h = len(arr)

# 	while l < h:
# 		mid = (l+h)//2
# 		if x >= arr[mid][0]:
# 			l = mid +1
# 		else:
# 			h = mid
# 	return l

# def main():
# 	MAX = int(1e9)
# 	for t in range(int(input())):
# 		n = int(input())
# 		XS = [[0 ,0] for _ in range(n)]
# 		YS = [[0 ,0] for _ in range(n)]

# 		for i in range(n):
# 			a ,b = map(int , input().split())
# 			XS[i][0]  ,XS[i][1] = a ,b
# 			YS[i][0]  , YS[i][1] = b ,a

# 		XS.sort()
# 		YS.sort()

# 		res = n

# 		i = 0
# 		while i < n:
# 			it = i
# 			while it < n and YS[it][0] == YS[i][0]: it += 1
# 			# idx = upper_bound(XS ,[YS[i][0] ,MAX]) # idk if MAX is neccessary
# 			idx = upper_bound(XS ,YS[i][0]) # idk if MAX is neccessary
# 			if it < n and idx < n:
# 				res = min(res ,idx - it)
# 			i = it

# 		# print(res)
# 		if res == n: res = -1

# 		print(res)
# if __name__ == '__main__':
# 	main()
# def upper_bound(a ,b): # binary search for pairs
# def upper_bound(arr , x):
# 	l = 0
# 	h = len(arr)

# 	while l < h:
# 		mid = (l+h)//2
# 		if x >= arr[mid]:
# 			l = mid +1
# 		else:
# 			h = mid
# 	return l

# def main():
# 	MAX = int(1e9)
# 	for t in range(int(input())):
# 		n = int(input())
# 		# XS = [[0 ,0] for _ in range(n)]
# 		# YS = [[0 ,0] for _ in range(n)]
# 		XS = [0 for i in range(n)]
# 		YS = [0 for i in range(n)]

# 		for i in range(n):
# 			a ,b = map(int , input().split())
# 			# XS[i][0]  ,XS[i][1] = a ,b
# 			XS[i] = a
# 			YS[i] = b
# 			# YS[i][0]  , YS[i][1] = b ,a

# 		XS.sort()
# 		YS.sort()

# 		res = n

# 		i = 0
# 		while i < n:
# 			it = i
# 			while it < n and YS[it] == YS[i]: it += 1
# 			# idx = upper_bound(XS ,[YS[i][0] ,MAX]) # idk if MAX is neccessary
# 			idx = upper_bound(XS ,YS[i]) # idk if MAX is neccessary
# 			if it < n and idx < n:
# 				res = min(res ,idx - it)
# 			i = it

# 		if res == n: res = -1

# 		print(res)
# if __name__ == '__main__':
# 	main()