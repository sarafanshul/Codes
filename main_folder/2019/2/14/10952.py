list=[]
while 1:
    a,b=map(int,input().split())
    if a==0 and b==0:
        break
    list.append(a+b)
for j in range(len(list)):
    print(list[j])
