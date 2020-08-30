

for _ in range(int(input())):
	n = int(input())
	*_figs , = map(int , input().split())
	_setfig = set(_figs)
	if len(_setfig) == 1:
		print(1)
		print("1 "*n)
	else:
		if not n&1:
			print(2)
			print("2 1 "*(n//2))
		else:
			for i in range(n):
				if _figs[i] == _figs[(i+1)%n]:
					j = 0
					pos = i+1
					ans = [0 for i in range(n)]
					while pos <n:
						ans[pos] = j +1
						pos += 1
						j ^= 1
					j = 0
					pos = i
					while pos >= 0:
						ans[pos] = j +1
						pos -= 1
						j ^= 1
					print(2)
					print(*ans)
					break
					
			else:
				print(3)
				print("1" ,"2 3 "*((n-1)//2))

