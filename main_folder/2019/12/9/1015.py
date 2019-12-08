from sys import stdin
a=int(input())
b=list(map(int,input().split()))
c=[]
for i in range(len(b)):
    count=0
    for j in range(len(b)):
        if b[i]>b[j]:
            count+=1
    c.append(count)

for i in range(len(c)-1):
    for j in range(i+1,len(c)):
        if c[i]==c[j]:
            c[j]+=1
for i in range(len(c)):
    print(c[i],end=" ")
