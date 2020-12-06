def main():
	t ,s = map(int , input().split())
	for _ in range(t):
		n = int(input())
		*a , = map(int , input().split())
		*b , = map(int , input().split())	
		if s == 1:
			a.sort()
			b.sort()
			_sch = set()
			_sch.add(a[0]) ,_sch.add(b[0]) # min
			for i in range(n):
				if (b[i] <= a[i]) or not (a[i] in _sch): 
					print("NO")
					break
				_sch.add(a[i]) , _sch.add(b[i])
			else: print("YES")
		else:
			print("YES")

if __name__ == '__main__':
	main()
	exit()