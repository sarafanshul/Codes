import sys
a=int(input())
b=list(map(int,sys.stdin.readline().split()))
d=[b[0]]
for i in range(1,a):
    if d[i-1]+b[i]>b[i]:
        d.append(d[i-1]+b[i])
    else:
        d.append(b[i])
print(max(d))
