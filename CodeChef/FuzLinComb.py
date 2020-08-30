
def subsetCount(arr, n):
	return (1 << n) - 1


N = int(input())
*a ,= map(int , input().split())

count = subsetCount(a, N)

for kvar in range(int(input())):    

    k = int(input())
    nwar = [a%k for i in a]
    cnt = count    

    for i in range(N):
        if not nwar[i]:
            cnt -= 1
    
    print(cnt)
