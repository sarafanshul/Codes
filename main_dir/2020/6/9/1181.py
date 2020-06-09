a=int(input())
list1=[]
for i in range(a):
    list1+=[input()]
set1=set(list1)
list2=sorted(list(set1))

for j in range(51):
    for k in range(len(list2)):
        if len(list2[k])==j:
            print(list2[k])
