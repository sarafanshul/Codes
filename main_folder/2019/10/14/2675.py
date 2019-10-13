a=int(input())
d=[]

for i in range(a):
    b,c=input().split()
    e=""
    for j in range(len(c)):
        e+=c[j]*int(b)
    d=d+[e]
for k in range(len(d)):
    print(d[k])
