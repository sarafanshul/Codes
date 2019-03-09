import sys
k=int(input())
list1=[]
for _ in range(k):
    a,b=map(int,input().split())
    tuple1=(b,a)
    list1.append(tuple1)
list1=sorted(list1)
for i in range(k):
    print("%d %d"%(list1[i][1],list1[i][0]))
