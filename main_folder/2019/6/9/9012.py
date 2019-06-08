a=int(input())
printlist=[]

for i in range(a):
    b=input()
    count=0
    if len(b)>=2 and len(b)<=50:
        if b[len(b)-1]=="(" or b[0]==')':
            printlist.append('NO')
        else:
            for j in range(len(b)):
                if b[j]=='(':
                    count+=1
                if b[j]==')':
                    count-=1
                    if count<0:
                        printlist.append('NO')
                        break
            if count==0:
                printlist.append('YES')
            if count>0:
                printlist.append('NO')
for z in range(len(printlist)):
    print(printlist[z])
