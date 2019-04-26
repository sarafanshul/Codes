a,b=map(int,input().split())
c=a*b
while b != 0:
    if a<b:
        (a,b)=(b,a)
    (a,b)=(b,a%b)
print(a)
print(c//a)
