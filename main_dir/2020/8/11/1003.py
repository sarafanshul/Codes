a=int(input())
abcd=[]
printlist=[]
list0=[1,0,1]
list1=[0,1,1]
abcd=[int(input()) for i in range(a)]
c=max(abcd)
for i in range(c-2):
    list0.append(list0[i+1]+list0[i+2])
    list1.append(list1[i+1]+list1[i+2])
for z in range(a):
    printlist.append(str(list0[abcd[z]])+" "+str(list1[abcd[z]]))
for k in range(len(printlist)):
    print(printlist[k])

