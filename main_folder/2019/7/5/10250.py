a=int(input())
where=[]
for i in range(a):
    b,c,n=map(int,input().split())
    room=1
    while 1:
        if n-b>0:
            room+=1
            n=n-b
        else:
            break
    if room<10:
        room='0'+str(room)


    floor=n%b
    if floor==0:
        floor=b
    where+=[str(floor)+str(room)]

for i in range(len(where)):
    print(where[i])
