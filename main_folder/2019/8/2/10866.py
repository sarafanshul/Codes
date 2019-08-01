a=int(input())
deque=[]
printlist=[]
for i in range(a):
    b=input().split()
    if b[0]=='push_front':
        deque.insert(0, b[1])

    elif b[0]=='push_back':
        deque.append(b[1])

    elif b[0]=='pop_front':
        if len(deque)==0:
            printlist.append(-1)
        else:
            printlist.append(deque[0])
            deque.remove(deque[0])

    elif b[0]=='pop_back':
        if len(deque)==0:
            printlist.append(-1)
        else:
            printlist.append(deque[len(deque)-1])
            deque.pop()

    elif b[0]=='size':
        printlist.append(len(deque))

    elif b[0]=='empty':
        if len(deque)==0:
            printlist.append(1)
        else:
            printlist.append(0)

    elif b[0]=='front':
        if len(deque)==0:
            printlist.append(-1)
        else:
            printlist.append(deque[0])

    elif b[0]=='back':
        if len(deque)==0:
            printlist.append(-1)
        else:
            printlist.append(deque[len(deque)-1])

for j in range(len(printlist)):
    print(printlist[j])
