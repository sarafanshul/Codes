a=input()
list=[]
for i in range(len(a)):
    list.append(a[i:])
list=sorted(list)
for i in list:
    print(i)
