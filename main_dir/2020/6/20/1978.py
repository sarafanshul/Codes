a=int(input())
b=list(map(int, input().split()))
c=[]
for i in range(len(b)):
    chk=True
    for j in range(2,b[i]):
        if b[i]%j==0:
            chk=False
            break
    if chk:
        c=c+[b[i]]
count=len(c)
if 1 in c:
    print(count-1)
else:
    print(count)
