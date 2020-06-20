list=[]
z=int(input())
for i in range(z):
    a,b=map(int,input().split())
    c=a*b
    while b != 0:
        if a<b:
            (a,b)=(b,a)
        (a,b)=(b,a%b)
    list.append(c//a)
for j in range(len(list)):
    print(list[j])
