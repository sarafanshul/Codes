list1=[]
list2=[]
list3=[]
a=int(input())
for i in range(a):
    b=input()
    list1.append(b)

for i in range(len(list1)):
    count=0
    for j in range(len(list1)):
        if list1[i]==list1[j]:
            count+=1
    list2.append(count)
z=max(list2)
for i in range(len(list1)):
    if list2[i]==z:
        list3.append(list1[i])
list3=sorted(list(set(list3)))
print(list3[0])
