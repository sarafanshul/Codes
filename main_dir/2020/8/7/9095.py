z=int(input())
list=[]
for z in range(z):
    list1=[1,2,4]
    a=int(input())
    if a<3:
        list.append(str(list1[a-1]))
        continue
    else:
        for i in range(3,a):
            list1.append((list1[i-1]+list1[i-2]+list1[i-3]))
    list.append(str(list1[-1]))
print("\n".join(list))
