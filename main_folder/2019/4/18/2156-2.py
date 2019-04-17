import sys
a=int(input())
list1=[0 for _ in range(10001)]
d=[0 for _ in range(10001)]
for i in range(1,a+1):
    list1[i]=int(sys.stdin.readline())
d[1]=list1[1]
d[2]=list1[1]+list1[2]
for i in range(3,a+1):
    d[i]=(max(d[i-3]+list1[i-1]+list1[i],d[i-2]+list1[i],d[i-1]))
print(d[a])
