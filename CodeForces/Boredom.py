
# c = [0 for i in range(100001)]


# def Func(i):
# 	global c
# 	# print(c[:10])
# 	if i == 0: return 0
# 	if i == 1: return c[1]

# 	return max(Func(i-1) , Func(i-2) + i*c[i])


# n = int(input())

# *arr , = map(int , input().split())


# x = m = 0
# for a in arr:
# 	c[a] += 1
# 	m = max(m , x)


# print(Func(m)) 


MAX_N = 100001

dp = [0 for i in range(MAX_N)]
c = [0 for i in range(MAX_N)]

n = int(input())
*arr , = map(int , input().split())

x = m = 0
for a in arr:
	c[a] += 1

dp[1] = c[1]

for i in range(2 ,MAX_N):
	dp[i] = max(dp[i-1] , dp[i-2]+i*c[i])

print(dp[MAX_N-1])