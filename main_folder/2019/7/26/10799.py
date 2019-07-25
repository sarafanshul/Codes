import sys
z= lambda: sys.stdin.readline().strip()
a=z()
list1=[]
count=0
for (i,a) in enumerate(a):
    if a=="(":
        list1.append(i)
    else:
        if i-list1[-1]==1:
            list1.pop()
            count+=len(list1)
        else:
            count+=1
            list1.pop()
print(count)
