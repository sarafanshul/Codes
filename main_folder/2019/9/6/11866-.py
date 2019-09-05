a,b =map(int,input().split())
c=b-1
printlist=[]
array=[i for i in range(1,a+1)]

for j in range(a):

    if c>=len(array):
        d=c-(b-1)

        c=b-(len(array)-d)
        print(c)

        printlist.append(array[c])
        array.remove(array[c])

    else :
        printlist.append(array[c])
        array.remove(array[c])
        print(c)

    c+=b-1

print(printlist)



