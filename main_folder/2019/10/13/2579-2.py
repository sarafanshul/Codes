import sys
list1=[]
z=int(input())
a=[0 for _ in range(301)]
d=[0 for _ in range(301)]
for i in range(1,z+1):
    a[i]=int(sys.stdin.readline())
d[1] = max(a[0]+a[1],a[1])
d[2] = max(a[0]+a[2],a[1]+a[2])
for i in range(3,z+1):
    d[i]=max(a[i]+a[i-1]+d[i-3],a[i]+d[i-2])
print(d[z])
