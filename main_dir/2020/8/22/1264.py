list1=[]
while 1:
    a=input()
    count=0
    if a=="#":
        break
    else:
        for i in range(len(a)):
            if a[i]=="a" or a[i]=="e" or a[i]=="i" or a[i]=="o" or a[i]=="u" or a[i]=="A" or a[i]=="E" or a[i]=="I" or a[i]=="O" or a[i]=="U":
                count+=1
        list1.append(count)
for i in list1:
    print(i)
