list2=[]
for i in range(int(input())):
    a=list(input())
    list1=[]
    for j in range(len(a)):
        if a[j]=="(":
            list1.append(a[j])
            continue
        else:
            if len(list1) !=0:
                list1.pop()
                continue
            else:
                list1.append(a[j])
                break
    if len(list1) >0:
        list2.append("NO")
    else:
        list2.append("YES")
for i in list2:
    print(i)
