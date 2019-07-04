N,L=map(int,input().split())
list2=[]
list3=[]
for i in range(1,N//L):
    sum=i
    for j in range(i+1,i+101):
        sum=sum+j
        if sum>N:
            break
        if sum==N:
            list=[]
            for z in range(i,j+1):
                list.append(z)
            list2.append(list)
            break;
for i in range(len(list2)):
    list3.append(len(list2[i]))
z=list3.index(min(list3))
list4=list2[z]
for i in range(len(list4)):
    print(list4[i],end=" ")
