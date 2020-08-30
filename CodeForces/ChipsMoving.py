# def listsub(arr1 , test , n):
# 	# print('a' , arr1 , test)
# 	out = []
# 	for i in range(n):
# 		# print(abs(test[i] - arr1[i])%2)
# 		out.append(abs(test[i]-arr1[i])%2)

# 	# print('a' ,out)
# 	return out


# n = int(input())
# *arr , = map(int , input().split())

# setarr = list(set(arr))

# cases = []
# for elem in setarr:
# 	cases.append((elem,)*n)

# cot = []

# for case in cases:
# 	ans = listsub(case , arr , n)
# 	# print(ans)
# 	cot.append(ans.count(1))

# # print(cot)
# print(min(cot))

# O(n) solution - counting odds

n = int(input())
*arr , = map(int , input().split())

cnto = 0 # counting odds(odd count)
for i in arr: cnto += i & 1

print(min(cnto , n-cnto))