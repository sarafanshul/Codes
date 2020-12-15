
def main(n , m):

	if m == n-1:
		print('0' + '10'*m) 

	elif m == n :
		print('10'*m)

	elif (m > n) and m <= 2*(n+1):
		
		if m > 2*(m-n-1) and n > (m-n-1):
			print('110'*(m-n-1) , end = '')
			new_m = m - 2*(m-n-1)
			new_n = n - (m-n-1)
			n = new_n
			m = new_m 

		ret = '10'*n + '1'
		m2 = m - n - 1
		
		for e in ret :
			if int(e):
				print('1', end = '')
				if m2:
					print('1', end = '')
					m2 -= 1
			else:
				print('0', end = '')

	else:
		print('-1')

n , m = map(int , input().split())
main(n , m)
