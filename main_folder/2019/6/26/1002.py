import math
list1=[]
for i in range(int(input())):
    x1,y1,r1,x2,y2,r2=map(int,input().split())
    len=math.sqrt((x1-x2)**2+(y1-y2)**2)
    if (x1,y1)==(x2,y2):
        if r1==r2:
            list1.append("-1")
        else:
            list1.append("0")
    else:
        min=abs(r1-r2)
        if len<r1+r2 and len>min:
            list1.append("2")
        elif len==r1+r2 or len==min:
            list1.append("1")
        else:
            list1.append("0")
print("\n".join(list1))
