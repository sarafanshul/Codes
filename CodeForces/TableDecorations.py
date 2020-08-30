
*col , = map(int , input().split())

result = sum(col)//3

col.sort()

if col[0] + col[1] < result:
	result = col[0] + col[1]

print(result)