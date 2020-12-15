n = int(input())
table = [[-1 for i in range(n)]for j in range(n)]
for k in range(n):
	table[0][k] = 1
	table[k][0] = 1

# print(table)
maxx = 1
for c in range(1, n):
	for r in range(1 , n):
		table[c][r] = table[c-1][r] + table[c][r-1]
		if maxx < table[c][r] : maxx = table[c][r]
print(maxx) 
