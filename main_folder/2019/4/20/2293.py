n,k=map(int,input().split())
list1=[0 for _ in range(1001)]
d=[0 for _ in range(10001)]
for i in range(1,n+1):
    list1[i]=int(input())

d[0]=1
for i in range(1,n+1):
    for j in range(list1[i],k+1):
        d[j]+=d[j-list1[i]]
print(d[k])
