# '''
# Conditions ->					[Implemented]
# 	1) Ap<Ap+1…<Aq 					*
# 	2) if p>L, then Ap<Ap−1			*
# 	3) if q<R, then Aq>Aq+1			*

# 	*Improvise the prefix sum array for subs_max
# '''
# '''
# 	*All elements are different {Pairwise Distinct}
# 		we need a max incraesing subsq like it decreases after 
# 		its end like [1,2],1 not [1,2],3
# 		same for decreasing from above => {3,|1,2|,1} ideal_max_inc
# '''
# '''
# problem found 
# 5 2
# 1 2 3 4 2
# [[0, 0], [1, 0], [2, 0], [3, 0], [0, 1]]
# [0, 1, 1, 1, 1]
# [0, 0, 0, 0, 1]
# 3 5
# NO
# {correct -> YES}
# Solution
# create anathor arr -> L->varies 
# ([R] - [R-1]) - ([L] - [L-1])
# '''
# def main():
# 	N, Q = map(int, input().split())
# 	*arr, = map(int, input().split())

# 	L_R_inc = [[] for i in range(N)]
# 	L_R_dec = [[] for i in range(N)]
# 	arr_2 = [[0, 0] for _ in range(N)] # [... , [inc ,dec] , ...]

# 	for i in range(1 ,N):
# 		if arr[i] > arr[i-1]: # Max_increasing
# 			arr_2[i][0] = arr_2[i-1][0] + 1
# 		else: # Max_decreasing (use else ->[PAIRWISE DISTINCT])
# 			arr_2[i][1] = arr_2[i-1][1] + 1

# 	for l in range(N):
# 		for r in range(l ,N):
# 			# l, r = L-1 ,R-1
# 			tmp = arr_2[l:r+1]

# 			L_R_inc.append()
# 			L_R_dec.append()

# 	# arr_2 = [[0, 0] for _ in range(N)] # [... , [inc ,dec] , ...]
# 	# pre_inc = [0 for _ in range(N)]  # fukin "id==" error
# 	# pre_dec = [0 for _ in range(N)]

# 	# for i in range(1 ,N):

# 	# 	pre_inc[i], pre_dec[i] = pre_inc[i-1], pre_dec[i-1] # prefix arr_formation

# 	# 	if arr[i] > arr[i-1]: # Max_increasing
# 	# 		arr_2[i][0] = arr_2[i-1][0] + 1
# 	# 		pre_inc[i] += 1 # start of new arr

# 	# 	else: # Max_decreasing (use else ->[PAIRWISE DISTINCT])
# 	# 		arr_2[i][1] = arr_2[i-1][1] + 1
# 	# 		pre_dec[i] += 1 # start of new arr

# 	# print(arr_2, pre_inc, pre_dec, sep='\n')

# 	for i in range(Q):
# 		L, R = map(int, input().split())
# 		# ans = not bool(pre_inc[R-1] - pre_dec[R-1] - pre_inc[L-1] + pre_dec[L-1])
# 		# print("YES" if ans else "NO")

# if __name__ == '__main__':
# 	main()
