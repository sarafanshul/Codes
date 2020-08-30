
n = int(input())
arr = list(map(int,input().split()))

myset = set()
low = n+1

for i in range(n):
    tmp = myset.copy()
    low = min(low,n-i)

    for j in range(n-1,i-1,-1):
        if arr[j] in tmp:
            break
        tmp.add(arr[j])
        low = min(low,j-i)
 
    if arr[i] in myset:
        break
    myset.add(arr[i])

print(low)