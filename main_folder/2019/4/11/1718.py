
a=list(input())
b=list(input())
while 1:
    if len(b)<len(a):
        b+=b
    else:
        break
for i in range(len(a)):
    if a[i]==" ":
        continue
    else:
        z=ord(b[i])-96
        if ord(a[i])-z <97:
            z-=26
        a[i]=chr(ord(a[i])-z)
for i in range(len(a)):
    print(a[i],end="")
