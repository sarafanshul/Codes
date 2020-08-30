# n = int(input())
# *arr , = map(int , input().split())
# print(set(arr))
# print(n - len(set(arr)))

n = int(input())
 
ls = list(map(int,input().split()))
 
myset = set()
 
mn = n+1
 
for i in range(n):
    tmp = myset.copy()
    mn = min(mn,n-i)
    for j in range(n-1,i-1,-1):
        if ls[j] in tmp:
            break
        tmp.add(ls[j])
        mn = min(mn,j-i)
 
    if ls[i] in myset:
        break
    myset.add(ls[i])
 
 
print(mn)