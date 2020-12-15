
n, m ,k = map(int , input().split())
*arr , = map(int , input().split()) 

D = [0 for _ in range(n+1)]

D[0] = arr[0]
D[n] = 0

for i in range(1,n):
	D[i] = arr[i] - arr[i-1]

queries = []
for i in range(1,m+1):
	L, R ,d = map(int , input().split())
	queries.append([L , R , d])

x = 0
if m <=k: x = k
else: x = m

DK = [0 for _ in range(x+1)]
out = [0 for i in range(x)]

for i in range(1,k+1):
	Lk, Rk = map(int , input().split())
	DK[Lk-1] += 1
	DK[Rk] -= 1

for i in range(k):
	if i == 0:
		out[i] = DK[i]
	else:
		out[i] = DK[i] + out[i-1]

# till here we know number of times 
# eack querry needs to operate
# print(out)

# operating querries
for i in range(m):
	L , R , d = queries[i]
	d *= out[i]
	D[L-1] += d
	D[R] -= d

for i in range(n):
	if i == 0:
		arr[i] = D[i]
	else:
		arr[i] = D[i] + arr[i-1]

print(*arr , sep = ' ')
