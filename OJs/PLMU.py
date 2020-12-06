
def binomialCoefficient(n, k) -> int:
	if not n : return 0
    # since C(n, k) = C(n, n - k) 
	if(k > n - k): 
		k = n - k 
    # initialize result 
	res = 1
    # Calculate value of  
    # [n * (n-1) *---* (n-k + 1)] / [k * (k-1) *----* 1] 
	for i in range(k): 
		res = res * (n - i) 
		res = res / (i + 1) 
	# print(res)
	return int(res) 
  

# for _ in range(int(input())):
def compute() -> int:
	N = int(input())

	*arr , = map(int , input().split())
	zeros = twos = 0
	for i in arr:
		if i == 0:
			zeros += 1
		if i ==2:
			twos += 1
	# zeros = str_inp.count('0')
	# twos  = str_inp.count('2')
	# print(twos , zeros)
	# print(zeros//2 + twos//2)
# consider repeation in sequence and subsequence
	ans = binomialCoefficient(zeros,2) + binomialCoefficient(twos , 2)
	# print(ans)
	return ans

def main():
	for _ in range(int(input())):
		print(compute())

if __name__ == '__main__':
	main()