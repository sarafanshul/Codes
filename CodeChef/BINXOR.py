# use PyPy3 for faster JIT
# for python 2 LOOOSERS :( 
if 2/3 == 2//3 : 
	input = raw_input
else: pass

# limitting BITCH
MOD = 1000000007

# $construct PASCAL triangle
factorial_table = [0 for _ in range(100001)]

# operate construction
def __init__() -> 'no explicit return':
	
	tmp = 1
	factorial_table[0] = 1

	for i in range(1 ,100001):
		tmp = (tmp*i)%MOD
		factorial_table[i] = tmp

# modular inverse of [A (mod C) is A^-1]%MOD
def mod_INV(base) -> int:
	return pow(base , MOD - 2 ,MOD)

def nCr(n , r) -> int:
	return (factorial_table[n]* 
		mod_INV((factorial_table[r]*
			factorial_table[n-r])%MOD))%MOD

# binXOR called for main compute 
def binXOR() -> int:

	N = int(input())
	input_a = input()
	input_b = input()

	n1 = n2 = ans = 0

	for current in input_a:
		if current == '1': 
			n1 += 1

	for current in input_b:
		if current == '1': 
			n2 += 1

	if n2 > n1: 
		n1 , n2 = n2 , n1

	minn = n1 - n2

	if (n1+n2) > N: 
		maxx = (2*N) - (n1 + n2)

	else: 
		maxx = n1 + n2

	for i in range(minn ,maxx+1 ,2): 
		ans = (ans + nCr(N ,i)) % MOD

	return ans

def main():

	# call compute function
	__init__() # one time function

	# for cases
	for _ in range(int(input())):
		print(binXOR())

# basic bitch like dineshC
if __name__ == '__main__':
# Python 3.7.3 (v3.7.3:ef4ec6ed12, Mar 25 2019, 21:26:53) [MSC v.1916 32 bit (Intel)] on win32
	main()
	exit()



# MOD = 1000000007

# # $construct PASCAL triangle
# factorial_table = [0 for _ in range(100001)]

# # operate construction
# def __init__():
	
# 	temp = 1
# 	factorial_table[0] = 1

# 	for i in range(1 ,100001):
# 		temp = (temp*i)%MOD
# 		factorial_table[i] = temp

# def mod_INV(base):
# 	return pow(base , MOD - 2 ,MOD)

# def nCr(n , r):
# 	return (factorial_table[n]* 
# 		mod_INV((factorial_table[r]*factorial_table[n-r])%MOD))%MOD

# __init__()

# for _ in range(int(input())):
# 	N = int(input())
# 	n1 = n2 = 0

# 	input_a = input()
# 	input_b = input()

# 	for current in input_a:
# 		if current == '1': n1 += 1

# 	for current in input_b:
# 		if current == '1': n2 += 1

# 	if n2 > n1: n1 , n2 = n2 , n1
# 	minn = n1 - n2

# 	if (n1+n2) > N:
# 		maxx = (2*N) - (n1 + n2)
# 	else:
# 		maxx = n1 + n2

# 	ans = 0

# 	for i in range(minn ,maxx+1 ,2):
# 		ans = (ans + nCr(N ,i)) % MOD

# 	print(ans)