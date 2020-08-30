from math import sqrt

n = int(input())

a = set()
a.add(1)
a.add(n*(n+1)//2)

for i in range(2 , int(sqrt(n))+2):
	
	if n%i == 0:

		m = n//i
		t1 = m * (2+(m-1)*i) // 2
		t2 = i*(2+(i-1)*m) // 2
		
		a.add(t1)
		a.add(t2)

print(*sorted(list(a)))