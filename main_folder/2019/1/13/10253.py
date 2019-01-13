list=[]
def gcd(a,b):
    while b != 0:
        if a<b:
            (a,b)=(b,a)
        (a,b)=(b,a%b)
    return a

a=int(input())
for i in range(a):
    a,b=map(int,input().split())
    while a != 1:
        z=b//a+1
        choiso=z*b//gcd(b,z)
        a=a*choiso//b -choiso//z
        b=choiso
        q=gcd(a,b)
        if gcd(a,b) != 1:
            a=a//q
            b=b//q
    list.append(b)
for j in range(len(list)):
    print(list[j])
