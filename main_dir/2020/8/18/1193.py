s=1
m=2
a=int(input())
while True:
    if a<=s:
        break
    else:
        s+=m
        m+=1
if a==1:
    print('1/1')
elif m%2==0:
    l=[]
    for i in range(1,m):
        l.append('%d/%d'%(m-i,i))
    print(l[a-(s-(m-1))-1])
elif m%2==1:
    l=[]
    for i in range(1,m):
        l.append('%d/%d'%(i,m-i))
    print(l[a-(s-(m-1))-1])
