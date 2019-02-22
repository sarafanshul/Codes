a=int(input())
count=0
if a>=0 and a<=9:
    a="0"+str(a)
else:
    a=str(a)
c=str(a)

while 1:
    b=int(a[0])+int(a[1])
    if b<10:
        b="0"+str(b)
    b=str(b)
    a=a[1]+b[1]
    count+=1
    if c==a:
        break
print(count)
