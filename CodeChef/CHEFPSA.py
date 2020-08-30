from collections import defaultdict

MOD = 1000000007


def factorial(fact:list) -> None:
	for i in range(2 ,100002):
		fact.append(fact[i-1]*i%MOD)
	return

def powers_Two(pow_2:list) -> None:
	for i in range(1 ,100002):
		pow_2.append(pow_2[i-1]*2%MOD)
	return



def main() -> None:

	fact = [1 ,1]
	factorial(fact)
	pow_2 = [1]
	powers_Two(pow_2)

	
	for _ in range(int(input())):
		
		N = int(input())
		*arr ,= sorted(map(int , input().split()))
		S = min(arr[0] ,0) + max(arr[2 * N-1] ,0) # |min| +|max|
		flag = True
		dict_pair = defaultdict(lambda : False)
		i = 0
		j = 2*N - 1
		zeros_out = 0
		z = 0

		while i <= j and z < N+1 :

			if arr[i] == S and zeros_out < 2:
				zeros_out += 1
				_key = min(arr[i] ,S-arr[i])
				dict_pair[_key] += 1
				i += 1
			elif arr[j] == S and zeros_out < 2:
				zeros_out += 1
				_key = min(arr[j] , S - arr[j])
				dict_pair[_key] += 1
				j -= 1
			elif arr[i] + arr[j] == S :
				_key = min(arr[i] ,arr[j])
				dict_pair[_key] += 1
				i  ,j = i+1 ,j-1
			else:
				flag = False
				break
			z += 1

		if z != N + 1 or not flag or zeros_out != 2:
			print(0)
			continue

		pairs = N - 1
		zer_pair = min(0 ,S)

		if dict_pair[zer_pair] == 2 :
			dict_pair[zer_pair] = 0
		else:
			dict_pair[zer_pair] -= 2

		minTwo = MOD - 2
		out = fact[pairs]

		memoization = defaultdict(lambda : -1)

		for p in dict_pair.keys():
			cnt = dict_pair[p]
		
			if cnt > 1 :
				factor = memoization[cnt]
				if factor == -1:
					factor = pow(fact[cnt] ,minTwo ,MOD) # modInverse
					memoization[cnt] = factor
				out = out*factor%MOD
		
			if p != S - p:
				out = out * pow_2[cnt] % MOD

		print(out)


if __name__ == '__main__':
	main()
