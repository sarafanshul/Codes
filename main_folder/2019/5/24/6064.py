a=int(input())
list=[]
for i in range(a):
    m,n,x,y=map(int,input().split())    
    b=x%n
    c=x-m
    first=True
    while True:
        c+=m
        if c%n==y%n:
            break
        if c%n==b and first==False:
            c=-1
            break
        first=False
    list+=[str(c)]
for i in range(len(list)):
    print(list[i])
