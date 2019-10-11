list=[]
for i in range(3):
    a=input()
    count=0
    for j in range(len(a)):
        if a[j] == '0':
            count+=1

    if count==1:
        list.append("A")
    elif count==2:
        list.append('B')
    elif count==3:
        list.append('C')
    elif count==4:
        list.append('D')
    else:
        list.append('E')

for z in range(len(list)):
    print(list[z])


