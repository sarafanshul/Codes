
n = int(input())

dp = [[0 , 0  , 0] for i in range(n)]

*a , = map(int , input().split())
*b , = map(int , input().split())

dp[0][0] = a[0]
dp[0][1] = b[0]

for i in range(1 ,n):
	dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]))
	dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i]
	dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i]

# print(dp)
print(max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])))