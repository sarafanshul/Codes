b = int(input())
g = int(input())
n = int(input())

mn = min(b , g)


a = []

for i in range(n+1):
	a.append([i , n-i])

print(a)