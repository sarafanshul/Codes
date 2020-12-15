# a%b = 0
for _ in range(int(input())):
	a ,b = map(int , input().split())
	if not a%b: print(0)
	else:print(b - a%b)