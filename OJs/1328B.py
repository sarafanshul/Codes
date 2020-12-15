for _ in range(int(input())):
	n ,k = map(int , input().split())
	_str = ["a" for _ in range(n)]
	for i in range(n-2 ,-1 ,-1):
		if k<=(n-i-1):
			_str[i] = "b"
			_str[n-k] = "b"
			break
		k -= (n-i-1)
	print("".join(_str))