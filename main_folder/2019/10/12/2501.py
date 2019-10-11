n,k=map(int,input().split())
list=[]
for i in range(1,n+1):
    if n%i==0:
        list.append(i)
if len(list)<k:
    print('0')
else:
    print(list[k-1])
