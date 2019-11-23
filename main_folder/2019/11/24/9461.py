list1=[1,1,1,2,2,3,4,5,7,9,12]
printlist=[]
for i in range(int(input())):
    a=int(input())
    for i in range(a-11):
        list1.append(list1[-1]+list1[-5])
    printlist.append(str(list1[a-1]))
    list1=[1,1,1,2,2,3,4,5,7,9,12]
print("\n".join(printlist))
