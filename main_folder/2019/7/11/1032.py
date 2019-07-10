a=int(input())
list1=[]
for _ in range(a):
    list1.append(list(input()))
list2=list1[0]
for i in range(len(list2)):
    for j in range(len(list1)):
        if list2[i] != list1[j][i]:
            list2[i]="?"
print("".join(list2))
