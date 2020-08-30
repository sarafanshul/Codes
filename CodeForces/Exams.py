
n = int(input())

days = []
for _ in range(n):
	ai , bi = map(int , input().split())
	days.append([ai , bi])

days.sort()

best = -1

for i in range(n):
	
	if best <= days[i][1]:
		best = days[i][1]
	else:
		best = days[i][0]

print(best)