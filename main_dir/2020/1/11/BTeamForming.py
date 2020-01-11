n = int(input())
*st , = map(int , input().split())
srtst = sorted(st)
# print(srtst)
prob = 0
for i in range(0 , n , 2):
	# print(i)
	prob += srtst[i+1] - srtst[i]
print(prob)