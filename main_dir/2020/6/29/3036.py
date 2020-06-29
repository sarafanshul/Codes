a=int(input())
list=list(map(int,input().split()))
list2=[]
for i in range(1,a):
    x=list[0]
    y=list[i]
    while y != 0 :
        if x<y:
            (x,y)=(y,x)
        (x,y)=(y,x%y)
    string=str(list[0]//x)+"/"+str(list[i]//x)
    list2.append(string)
for j in range(len(list2)):
    print(list2[j])
