list=[]
try:
    while 1:
        a,b=map(int,input().split())
        list.append(a+b)
except:
    for i in range(len(list)):
        print(list[i])
    exit()
