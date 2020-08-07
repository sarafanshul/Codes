list=[]
for i in range(int(input())):
    a,b=map(int,input().split())
    list.append(a)
    list.append(b)
for j in range(len(list)//2):
    print('Case #%d: %d + %d = %d'%(j+1,list[2*j],list[2*j+1],list[2*j]+list[2*j+1]))
