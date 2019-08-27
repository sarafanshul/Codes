import sys
list1=[]
countlist=1
max=1
a=int(input())
for _ in range(a):
    list1.append(int(sys.stdin.readline()))
list1=sorted(list1)
max_where=list1[0]
for i in range(1,a):
    if list1[i]==list1[i-1]:
        max+=1
    else:
        max=1
    if countlist<max:
        countlist=max
        max_where=list1[i]
print(max_where)
