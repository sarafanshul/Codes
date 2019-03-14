import sys
a=int(input())
b=list(map(int, sys.stdin.readline().split()))
b=b[::-1]
d=[1 for _ in range(a)]
for i in range(0,a):
    for j in range(0,i):
        if (b[j]<b[i]) and (d[i]<d[j]+1):
            d[i]=d[j]+1
print(max(d))
