
# def cd_1(n , k):
# 	boxes = [n//k for _ in range(k)]
# 	return(boxes)

# def cd_2(n , k):
# 	# boxes = [int(0) for _ in range(k)]
# 	boxes = [0]*k
# 	# boxes = []
# 	print(boxes)
# 	for i in range(n//k):
# 		boxes[boxes.index(min(boxes))] += k
# 		# boxes[boxes.index(0)] += k
# 		# boxes.append(k)
# 	return(boxes)


for case in range(int(input())):
	n , k = list(map(int , input().split()))
	if (n//k)%k==0: print('NO')
	else: print('YES')
