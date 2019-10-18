a=int(input())
list1=[]
sumlist=[]
print1=[]
for i in range(a):
    even=[]
    list2=[]
    sum=0
    list1=input().split()
    for j in range(len(list1)):
        list2.append(int(list1[j]))

    for i in range(len(list2)):
        if list2[i]%2==0:
            sum=sum+list2[i]
            even.append(list2[i])
    sumlist.append(sum)
    print1.append(min(even))
for i in range(len(sumlist)):
    print(sumlist[i], print1[i])
