import math
a=int(input())
for i in range(a):
    count=0
    x1,y1,x2,y2=map(int,input().split())
    for j in range(int(input())):
        cx,cy,r=map(int,input().split())
        d1=math.sqrt((cx-x1)**2+(cy-y1)**2)
        d2=math.sqrt((cx-x2)**2+(cy-y2)**2)
        if d1>r:
            if d2>r:
                pass
            else:
                count+=1
        if d1<r:
            if d2<r:
                pass
            else:
                count+=1
    print(count)
