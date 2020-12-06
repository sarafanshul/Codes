# def main():
# 	MAX = int(1e9)
# 	for t in range(int(input())):
# 		n = int(input())
# 		# g = [[0 ,0] for i in range(n)]
# 		ed = [0 for i in range(n-1)]
# 		# print(g)
		
# 		for id in range(n-1): #
# 			x ,y ,z = map(int , input().split())
# 			x -= 1
# 			y -= 1
# 			ed[id] = z
# 			# g[x].append([y ,id])
# 			# g[y].append([x ,id])
# 		# print(g)

# 		ed.sort(reverse = True)
# 		# values = [0 for i in range(n)]
# 		cost = [0 for i in range(n-1)]

# 		# for i in range(n):
# 		# 	values[i] = int(input())
# 		*values , = sorted(map(int , input().split()))

# 		# values.sort()

# 		dq = values

# 		res = 0
# 		while len(ed):
# 			while len(dq) and dq[0] < ed[-1]:
# 				dq.pop(0) # or pop([0])
# 				dq.append(MAX)
# 				res += 1
# 			dq.pop(0)
# 			ed.pop()

# 		print(res)

# if __name__ == '__main__':
# 	main()

def lower_bound(a ,x):
	l = 0
	h = len(a)
	while l < h:
		mid = (l+h)//2
		if x <= a[mid]:
			h = mid
		else:
			l = mid + 1

	return l

def main():
	MAX = int(1e9)
	for t in range(int(input())):
		ed = []
		for i in range(int(input()) -1): #
			x ,y ,z = map(int , input().split())
			ed.append(z)
		ed.sort(reverse = True)
		*dq , = sorted(map(int , input().split()))
		res = 0
		while len(ed):
			# while len(dq) and dq[0] < ed[-1]: # binary search it
			# # and mylist = mylist[2:-2] insted of pop ,del mylist[:2];del mylist[-2:]
			# 	dq.pop(0)
			# 	dq.append(MAX)
			# 	res += 1
			idx = lower_bound(dq ,ed[-1])
			mn = min(idx ,len(dq))
			del dq[mn:]
			dq.extend([MAX]*mn)

			dq.pop(0)
			ed.pop()
		print(res)

if __name__ == '__main__':
	main()