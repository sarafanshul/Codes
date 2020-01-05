n , k = map(int , input().split())
*m  ,= map(int , input().split())

diff = []

for i in range(1 , n):
	diff.append(m[i-1]-m[i])

# print(diff)
diff.sort()
res = m[-1] - m[0]

# print(diff)
for i in range(k-1):
	res += diff[i]

print(res)