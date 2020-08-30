for _ in range(int(input())):
	arr = [0 for i in range(11)] 	# store only max element
	for i in range(int(input())):
		Pi , tmp = map(int , input().split())
		arr[Pi - 1] = max(arr[Pi - 1] , tmp)
	print(sum(arr[:8]))