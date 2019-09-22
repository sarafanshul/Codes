b=""
list1=[]
list2=[]
try:
    while 1:
        a=input()
        b+=a
except:
    for i in range(97,123):
        count=0
        for j in range(len(b)):
            if chr(i)==b[j]:
                count+=1
        list1.append(count)
    z=max(list1)
    for i in range(len(list1)):
        if list1[i]==z:
            list2.append(chr(i+97))
    for z in list2:
        print(z,end="")
    exit()
