a=[int(input()) for z in range(9)]
printlist=[]
for i in range(8):
    for j in range(i+1,9):
        b=[a[z] for z in range(len(a))]
        del b[j]
        del b[i]
        sum=0
        list2=[]
        for z in range(len(b)):
            list2.append(b[z])
            sum+=b[z]
            if sum==100 and len(list2)==7:
                for q in range(len(list2)):
                    printlist.append((list2))
                    break
                break
c=sorted(printlist[0])
for j in range(len(c)):
    print(c[j])
