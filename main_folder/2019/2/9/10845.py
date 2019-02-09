a=int(input())
que=[]
printlist=[]
for i in range(a):
    b=input().split()
    if b[0]=='push':
        que.append(b[1])

    elif b[0]=='pop':
        if len(que)==0:
            printlist.append(-1)
        else:
            printlist.append(que[0])
            que.remove(que[0])

    elif b[0]=='size':
        printlist.append(len(que))

    elif b[0]=='empty':
        if len(que)==0:
            printlist.append(1)
        else:
            printlist.append(0)

    elif b[0]=='front':
        if len(que)==0:
            printlist.append(-1)
        else:
            printlist.append(que[0])
    elif b[0]=='back':
        if len(que)==0:
            printlist.append(-1)
        else:
            printlist.append(que[len(que)-1])
for j in range(len(printlist)):
    print(printlist[j])
