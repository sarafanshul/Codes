# # brute force algorithm
# import sys
# memo = dict()
# sys.setrecursionlimit(9000000)
# def fibonacci(num , a , b):
# 	if num in memo.keys():
# 		return memo[num]
# 	else:
# 		if num == 0:
# 			return a
# 		if num == 1:
# 			return b
# 		memo[num] = fibonacci(num-1 , a ,b) ^ fibonacci(num-2 , a , b)
# 		return memo[num]

# # print(fibonacci(12310,325,265))
# for i in range(1, 10):
# 	print(i%3, fibonacci(i , 3,4))

'''
=== output ===
1 4
2 7
0 3
1 4
2 7
0 3
1 4
2 7
0 3
clearly output is dependend on n%3

1) n%3 == 0 : a
2) n%3 == 1 : b
3) else     : a^b    
'''
for case in range(int(input())):
	a , b , n = map(int , input().split())
	if n%3 == 0: print(a)
	elif n%3 == 1: print(b)
	else: print(a^b)