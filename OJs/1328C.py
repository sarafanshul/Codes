
for i in range(int(input())):
	n = int(input())
	# *num  ,= map(str , input().split())
	num = input()
	b = ["0" for _ in range(n)]
	a = ["0" for _ in range(n)]
	for i in range(n):
		if num[i] == "1":
			a[i] = "1"
			b[i] = "0"
			for j in range(i+1 ,n):
				b[j] = num[j]
			break
		else:
			a[i] = b[i] = str(int(num[i])//2)
	print("".join(a))
	print("".join(b))