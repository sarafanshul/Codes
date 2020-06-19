import math
a=int(input())
list1=[]
for i in range(0,a+1):
    list1.append(i)
    for j in range(1,int(math.sqrt(i))+1):
        if list1[i]>list1[i-j*j]+1:
            list1[i]=list1[i-j*j]+1
print(list1[a])
