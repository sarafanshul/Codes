import sys
list1=[]
max=0
for _ in range(int(input())):
    list1.append(int(sys.stdin.readline()))
a=sorted(list(set(list1)))
for i in range(len(a)):
    if list1.count(a[i])>max:
        max=list1.count(a[i])
        max_where=a[i]
print(max_where)
