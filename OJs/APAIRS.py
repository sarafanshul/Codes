DP = [i for i in range(110)] # max sum of str(10e12) ?

def len_C(num ):
	ln = sm = z2 = 0
	for i in num:
		# print(i)
		if i == '0': z2 += 1
		sm += ord(i) - 48
		ln += 1
	return (ln ,sm ,z2)

MOD = 1000000007

def apair(num1 ,num2):
	num1 , num2 = str(num1) , str(num2)
	# num1 = '3178'
	# num2 = '01029'
	len1  ,sum1 ,z1= len_C(num1)
	len2  ,sum2 ,z2= len_C(num2) # N
	# if DP[abs(sum1-sum2)] != -1: return DP[abs(sum1-sum2)] + z2


	if len1 > len2:
		num2 = '0'*(len1-len2) + num2
	else:
		num1 = '0'*(len2-len1) + num1
		# print(z1 ,z2)
	tmp = 1 if z1!=z2 else 0
	if len2 == len1:
		return DP[abs(sum1-sum2)]
	elif DP[abs(sum1-sum2)] != -1: return DP[abs(sum1-sum2)]+abs(len2-len1) - tmp
	# print(num1 , num2)
	# MAIN ALGO
	num1_sort = sorted(num1 ,key = lambda x: ord(x)) # list ,Nlog(N)
	num2_sort = sorted(num2 ,key = lambda x: ord(x))

	# print(num1_sort ,num2_sort)
	# for 

	summ = 0

	for i in range(len2): # N
		summ += abs(ord(num1_sort[i]) - ord(num2_sort[i]))
		if summ >= MOD : summ -= MOD

	DP[abs(sum1-sum2)] = summ

	return summ

# O(2N + 2Nlog(N) + N) for operation
# solve for R and save for L / use dp
# (1->R - 1->L)
# create a dp based on sum of digits

def main():
	for t in range(int(input())):
		OUT = 0
		L ,R = map(int , input().split())
		for i in range(L ,R+1):
			for j in range(L ,R+1):
				OUT += apair(i ,j)
				if OUT >= MOD: OUT -= MOD

		print(OUT)
	print(DP)

if __name__ == '__main__':
	main()