a=int(input())
b=int(input())
a=a-a%100
while 1:
    if a%b==0:
        break
    else:
        a+=1
c=a%100
if c<10:
    print("0"+str(c))
else:
    print(c)
