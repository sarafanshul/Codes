x,y,w,h=map(int,input().split())
if h-y>y:
    length1=y
else:
    length1=h-y
if w-x>x:
    length2=x
else:
    length2=w-x
print(min(length1,length2))
