list1=[]
while 1:
    try:
        list1.append(input())
    except EOFError:
        for i in range(len(list1)):
            print(list1[i])
        exit()
