# https://stackoverflow.com/questions/45335975/trying-to-complete-google-foo-bar-level-3-queue-to-do-and-keep-exceeding-time

def answer(s ,ln):
	def xor_util(x ,y):
		# print(f'{__name__} = > {x} ,{y}')
		def _xor_till(z):
			zz = z%4
			if(zz == 0): return z
			elif(zz == 1): return 1
			elif(zz == 2): return z+1
			else : return 0
		return _xor_till(y)^_xor_till(x-1)
	
	ans = 0
	for i in range(ln , 0 ,-1):
		if(s == s+i-1): ans ^= s
		else :ans ^= xor_util(s ,s+i-1)
		# print(f's = {s} -> {s+i-1} = {xor_util(s ,s+i-1)} ,{ans}')
		s += ln
	return ans

def main():
	s = int(input())
	ln = int(input())
	print(answer(s ,ln))

if __name__ == '__main__':
	main()