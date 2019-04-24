a=[0 for _ in range(301)]
d=[0 for _ in range(301)]
n=int(input())
for i in range(1,n+1):
    a[i]=int(input())
d[1]=a[1]
d[2]=a[1]+a[2]
for i in range(3,n+1):
    d[i]=max(d[i-2]+a[i],d[i-3]+a[i]+a[i-1])
print(d[n])
