def check(arr , k):
	if k == 0 and arr[0] > 1: return 1
	elif k == 0 and arr[0] == 1 : return -1
	elif k <= n-1:
		if arr[k] != arr[k-1]:
			return arr[k-1]
		return -1
	elif k == n :
		return arr[k-1]

n , k = map(int , input().split())
arr = sorted(list(map(int , input().split())))
print(check(arr , k))

