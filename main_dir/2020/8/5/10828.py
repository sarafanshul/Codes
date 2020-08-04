a=int(input())
stack=[]
printlist=[]
for i in range(a):
    b=input().split()
    if b[0]=='push':
        stack.append(b[1])

    elif b[0]=='pop':
        if len(stack)==0:
            printlist.append(-1)
        else:
            printlist.append(stack[len(stack)-1])
            stack.pop()

    elif b[0]=='size':
        printlist.append(len(stack))

    elif b[0]=='empty':
        if len(stack)==0:
            printlist.append(1)
        else:
            printlist.append(0)

    elif b[0]=='top':
        if len(stack)==0:
            printlist.append(-1)
        else:
            printlist.append(stack[len(stack)-1])
for j in range(len(printlist)):
    print(printlist[j])
