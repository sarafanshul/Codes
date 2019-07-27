list1=[]
list2=[]
list3=[]
list4=[]
while 1:
    try:
        count1=0
        count2=0
        count3=0
        count4=0
        a=input()
        for i in range(len(a)):
            if ord(a[i])>= 97 and ord(a[i])<=122:
                count1+=1
            elif ord(a[i])>= 65 and ord(a[i])<=90:
                count2+=1
            elif a[i] ==" ":
                count4+=1
            else:
                count3+=1
        list1.append(count1)
        list2.append(count2)
        list3.append(count3)
        list4.append(count4)
    except:
        for i in range(len(list1)):
            print("%d %d %d %d"%(list1[i],list2[i],list3[i],list4[i]))
        exit()
