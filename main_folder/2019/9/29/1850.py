a,b=map(int,input().split())
while b != 0:
    if a<b:
        (a,b)=(b,a)
    (a,b)=(b,a%b)
print("1"*a)
