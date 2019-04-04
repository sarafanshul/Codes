list1=[]
while 1:
    a=input()
    sum=0
    if a=="0":
        break
    else:
        for i in range(len(a)):
            if a[i]=="1":
                sum+=2
            elif a[i]=="0":
                sum+=4
            else:
                sum+=3
        sum+=len(a)+1
        list1.append(sum)
for i in list1:
    print(i)
