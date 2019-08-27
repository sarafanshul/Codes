import sys
a=int(input())
list1=[]
for _ in range(a):
    list1.append(tuple(map(int,input().split())))
list1=sorted(list1)
for i in range(a):
    print("%d %d"%(list1[i][0],list1[i][1]))
