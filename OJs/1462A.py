for _ in range(int(input())):
	n = int(input())
	*a , = map(int , input().split())
	b = []
	for i in range(len(a) // 2):
		b.append(a[i])
		b.append(a[-(i+1)])
	if(n%2 == 1):
		b.append(a[n//2])
	print(*b)