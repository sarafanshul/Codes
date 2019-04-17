a=int(input())
list1=[0]*31
list1[0]=1
for i in range(2,a+1,2):
    list1[i]=3*list1[i-2]
    for j in range(4,i+1,2):
        list1[i]+=2*list1[i-j]
print(list1[a])
