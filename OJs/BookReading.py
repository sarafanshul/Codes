
for case in range(int(input())):

	n , m = map(int , input().split())

	digits = [0 for i in range(10)]
	summ = 0
	n = n//m

	for i in range(10):
		digits[i] = ((i+1)*m)%10
	
	for i in range(n%10):
		summ += digits[i]

	print(summ + n//10*sum(digits))