import sys
a=int(input())
b=list(map(int, sys.stdin.readline().split()))
c=b[::-1]
d=[1 for _ in range(a)]
e=[1 for _ in range(a)]

for i in range(0,a):
    for j in range(0,i):
        if (b[j]<b[i]) and (d[i]<d[j]+1):
            d[i]=d[j]+1
        if (c[j]<c[i]) and (e[i]<e[j]+1):
            e[i]=e[j]+1
e=e[::-1]
for i in range(len(d)):
    d[i]=d[i]+e[i]
print(max(d)-1)
