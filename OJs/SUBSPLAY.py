# # for _ in range(int(input())):
# # 	N = int(input())
# # 	st = input()
# # 	for K in range(1 , N):
# # 		flag = 0

# # 		for j in range(N): 
# # 			if j+k > N : break
# # 			ck = st[j:j+K]
# # 			if ck in st[j+1::]:
# # 				flag = 1
# # 				break
# # 		if not flag:
# # 			break

# # 	print(K)

# from math import pow
# from functools import reduce

# class LCS(object):

# 	def longestDupSubstring(self, S):
# 		A = [ord(c) - 97 for c in S]

# 		def test(L):
# 			p = pow(26, L)
# 			cur = reduce(lambda x, y: (x * 26 + y) , A[:L], 0)
# 			seen = {cur}
# 			for i in range(L, len(S)):
# 				cur = (cur * 26 + A[i] - A[i - L] * p) 
# 				if cur in seen: return i - L + 1
# 				seen.add(cur)

# 		res, lo, hi = 0, 0, len(S)
# 		while lo < hi:
# 			mi = (lo + hi + 1) // 2
# 			pos = test(mi)
# 			if pos:
# 				lo = mi
# 				res = pos
# 			else:
# 				hi = mi - 1
# 		return S[res:res + lo]

# if __name__ == '__main__':
# 	# for _ in range(int(input())):
# 	# 	N = int(input())
# 	# 	a = LCS()
# 	# 	print(len(a.longestDupSubstring(input())))
# 	a = LCS()
# 	b = a.longestDupSubstring('atcgatcga')
# 	print(len(b))

def compute() -> int :

	N = int(input())
	s = input()
	ans = 0
	pst = [-1 for i in range(26)]

	for i in range(N-1 ,-1 ,-1):
		if pst[ord(s[i]) -97] != -1:
			ans = max(ans ,N -(pst[ord(s[i]) -97] -i))
		pst[ord(s[i]) -97] = i
	
	return ans

def main():
	for _ in range(int(input())):
		print(compute())

if __name__ == '__main__':
	main()