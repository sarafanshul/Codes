n = int(input())
*m , = map(int , input().split())

prear = []
m.sort()
prear.append(m[0])

count = j = 1
i = 0

while j<n:
	if prear[i] <= m[j]:
		i += 1
		count += 1
		prear.append(prear[i-1] + m[j])
	j += 1 

print(count)


