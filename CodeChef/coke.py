

for case in range(int(input())):
	inp = list(map(int , input().split()))
	N , M , K , L , R = inp
	p = []
	for n in range(N):
		C , P = map(int, input().split())
		# t = C
		for tmp in range(M):
			if C > K+1:
				C = C - 1
			elif C < K-1:
				C = C + 1
			else:
				C = K
			# print('C,N',C , n)
			# print('pr1',p)
		if C in list(range(L , R+1)):
			p.append(P)
		# print('pr2',p)
	# print(min(p))
	if len(p) == 0:
		print(-1)
	else:
		print(min(p))