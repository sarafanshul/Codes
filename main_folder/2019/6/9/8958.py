a=int(input())
b=[]
for i in range(a):
    sum=0
    count=0
    c=input()
    for j in range(len(c)):
        if c[j]=='X':
            count=0
        else:
            count+=1
            sum+=count
    b+=[sum]
for k in range(len(b)):
    print(b[k])
