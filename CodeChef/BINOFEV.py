# MOD = 998244353

# # def gcdExtended(a ,b ,x ,y):
# # 	if a == 0:
# # 		x = 0
# # 		y = 1
# # 		return (x ,y ,b)

# # 	x1 = y1 = 0
# # 	gcd = gcdExtended(b%a ,a ,x1 ,y1)
# # 	x = y1 - (b/a)*x1
# # 	y = x1
# # 	return gcd

# # def modInverse(b ,m):
# # 	x = y = 0
# # 	x ,y ,g = gcdExtended(b ,m ,x ,y)

# # 	if g != 1:
# # 		return -1

# # 	return (x%m +m)%m

# # def modDivide(a ,b ,m):
# # 	a %= m
# # 	inv = modInverse(b ,m)
# # 	if inv == -1:
# # 		return -1
# # 	else:
# # 		return (inv*a)%m

# import math 
# # Function to find modulo inverse of b. It returns  
# # -1 when inverse doesn't  
# # modInverse works for prime m 
# def modInverse(b,m): 
# 	g = math.gcd(b, m)  
# 	if (g != 1): 
# 		return -1
# 	else: 
# 		return pow(b, m - 2, m) 
  
  
# # Function to compute a/b under modulo m  
# def modDivide(a,b,m): 
# 	a = a % m 
# 	inv = modInverse(b,m) 
# 	if(inv == -1):  
# 		return -1
# 	else:
# 		return (inv*a)%m

# for _ in range(int(input())):
# 	n , p , r = map(int , input().split())

# 	ans = 0
# 	num = den = 1

# 	for i in range(n+1):
# 		pp = pow(p ,i ,MOD)
# 		if pp >= r:
# 			num = 1
# 			for j in range(min(r ,pp-r)):
# 				num = (num*(pp-j))%MOD
# 				num = (modDivide(num ,j+1 ,MOD))%MOD
# 			ans = (ans +num)%MOD

# 	print(ans)


# based on fermat little theorem 
# 	because MOD == prime

# from collections import defaultdict

# MOD = 998244353

# def ncr(n, r, p): 
# 	num = den = 1 
# 	for i in range(r): 
# 		num = (num * (n - i)) % p 
# 		den = (den * (i + 1)) % p 
# 	return (num * pow(den,  
# 			p - 2, p)) % p 

# for _ in range(int(input())):

# 	memo = defaultdict(lambda : -1) 
# 	N ,n ,r = map(int , input().split())
# 	summ = 0
# 	for i in range(N+1):

# 		pi = pow(n ,i ,MOD)
# 		print(pi)
# 		if memo[pi] == -1:
# 			memo[pi] = ncr(pi ,r ,MOD)
		
# 		summ = (summ + memo[pi])%MOD

# 	print(summ)

# different approach based on ~fft kinda


# MOD = 998244353

# # custom pow reccursive
# def power(a:int ,b:int) -> int:
# 	if b == 0:
# 		return 1
# 	num = power(a ,b//2)
# 	num = (num*num)%MOD
# 	if b%2:
# 		return (num*a)%MOD
# 	else:
# 		return num

# def inverse(a):
# 	return power(a ,MOD - 2)

# def get_coeff(poly ,l ,r):
# 	if l == r :
# 		poly = [-1*(l) , 1]
# 		if poly[0] != 0:
# 			poly[0] = poly[0] + MOD

# 		return poly

# 	mid = (l+r)//2
# 	left = [0 for i in range(mid - l + 2)]
# 	right = [0 for i in range(r- (mid+1) + 2)]

# 	# get_coeff(left ,l ,mid)
# 	# get_coeff(right ,mid+1 ,r)
# 	left = get_coeff(left ,l ,mid)
# 	right = get_coeff(right ,mid+1 ,r)
# 	# print(left ,right)

# 	for i in range(len(left)):
# 		for j in range(len(right)):
# 			temp = (left[i]*right[j])%MOD
# 			poly[i + j] = (poly[i+j] + temp)%MOD
# 			# print(poly[i+j] ,temp)

# 	return poly #

# def main():

# 	for i in range(int(input())):
# 		n ,p ,r = map(int , input().split())

# 		fact = 1
# 		for i in range(1 ,r+1):
# 			fact = (fact*i)%MOD

# 		fact = inverse(fact)
# 		# fact = pow(fact ,MOD - 2 ,MOD)

# 		poly = [0 for i in range(r+1)]
# 		get_coeff(poly ,0 ,r-1)
# 		# print(poly)
# 		# wrong power
# 		ans = 0
# 		for i in range(1 ,r+1):
# 			# num = pow(p ,(n+1)*i ,MOD) - 1 # md her
# 			num = (power(p ,(n+1)*i) - 1)%MOD
# 			# denom = pow(p ,i ,MOD) - 1
# 			denom = (power(p ,i) - 1)% MOD
# 			# print(num ,denom)
# 			if denom != 0:
# 				denom = inverse(denom)
# 				# denom = pow(denom ,MOD - 2 ,MOD)
# 				ans = (ans + ((num*denom)%MOD*poly[i])%MOD)%MOD
# 			else:
# 				ans = (ans + ((n+1)%MOD*poly[i])%MOD)%MOD
# 			# print(ans)
# 		ans = (ans*fact)%MOD
# 		print(ans)

# if __name__ == '__main__':
#  	main() 

MOD = 998244353
primitive_i = 332748118
primitive = 3
# primitive_i is the inverse of the primitive root of MOD
from math import log2
# custom pow reccursive
def power(a:int ,b:int) -> int:
	if b == 0:
		return 1
	num = power(a ,b//2)
	num = (num*num)%MOD
	if b%2:
		return (num*a)%MOD
	else:
		return num

# use pow(a ,MOD-2) insted
def inverse(a:int) -> power :
	return power(a ,MOD - 2)

def fft(a:list ,n:int ,invert:int) -> None:
	j = 0
	for i in range(1 ,n):
		bit = n>>1
		while j&bit:
			j ^= bit
			bit >>= 1
		j ^= bit

		if i < j:
			a[i] ,a[j] = a[j] ,a[i]

	l = 2
	while l <= n:
		v = MOD -1
		v //= l

		w_cur = power(primitive_i ,v) if invert else power(primitive ,v)
		j = 0
		while j <n:
			w = 1
			for i in range(l//2):
				# print(i ,l)
				first = a[i + j]
				second = w*a[i+j+l//2]%MOD
				a[i+j] = first + second if first+second < MOD else first + second -MOD
				a[i+j+l//2] = first - second if first -second >= 0 else first - second + MOD

				w = w*w_cur % MOD
			j += l
		l <<= 1

	if invert:
		n_i = inverse(n)
		for i in range(n):
			a[i] = a[i]*n_i % MOD


def get_coefficients(poly:list ,siz:int ,l:int ,r:int) -> list:
	if l == r:
		poly[0] = -1*(l)
		poly[1] = 1

		if poly[0] != 0:
			poly[0] = poly[0] + MOD

		return poly

	mid = (l+r)//2
	left = [0 for i in range(siz)]
	right = [0 for i in range(siz)]

	l_cap = int(log2(mid-l+1)) + 1
	l_siz = 1 << l_cap
	r_cap = int(log2(r - mid)) + 1
	r_siz = 1 << r_cap

	left = get_coefficients(left ,l_siz ,l ,mid)
	right = get_coefficients(right ,r_siz ,mid+1 ,r)

	# print(left ,right ,siz)
	fft(left ,siz , False)
	fft(right ,siz ,False)

	for i in range(siz):
		poly[i] = left[i]*right[i]%MOD

	fft(poly ,siz ,True)

	return poly

def main():
	facto = [0 ,1]
	for i in range(2 ,100001):
		# facto[i] = facto[i-1]*i%MOD
		facto.append(facto[i-1]*i%MOD)

	for t in range(int(input())):
		
		n ,p ,r = map(int , input().split())
		fact = inverse(facto[r])
		cap = int(log2(r) + 1)
		siz = 1 << cap

		poly = [0 for i in range(siz)]

		get_coefficients(poly ,siz ,0 ,r-1)

		ans = 0
		for i in range(1 ,r+1):
			num = (power(p ,(n+1)*i)-1)
			if num < 0:
				num += MOD
			denom = (power(p ,i) - 1)
			if denom < 0:
				denom += MOD
			if denom != 0:
				denom = inverse(denom)
				term = num *denom%MOD
				tet = term*poly[i]%MOD
				ans += tet

				if ans >= MOD:
					ans -= MOD
			else:
				tet = ((n+1)%MOD)*poly[i]%MOD
				ans += tet

				if ans >= MOD:
					ans -= MOD

		ans = ans*fact%MOD
		print(ans if ans >= 0 else ans + MOD)

if __name__ == '__main__':
	main()
