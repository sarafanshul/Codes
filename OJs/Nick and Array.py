# n = int(input())
# *m , = map(int , input().split())

# dp = [[0,0] for i in range(n+1)] 

# for i in range(n):
# 	dp[i][0] = m[i]
# 	dp[i][1] = -m[i]-1

# prod = [1]
# temp = 1
# for i in range(n-1):
# 	prod.append( temp * max(d[i][0]*d[i+1][0] ,
# 				d[i][0]*d[i+1][1],
# 				d[i][1]*d[i+1][0],
# 				d[i][1]*d[i+1][1])
# 				)
# 	temp = prod[i]

n = int(input())
*m , = map(int , input().split())

mn = 1e11 +69
mnn = 0

for i in range(n):
	if m[i] >= 0 : m[i] = -m[i] - 1
	if m[i] < mn :
		mn = m[i]
		mnn = i

if n&1 :
	m[mnn]  = -m[mnn] - 1


print(*m)