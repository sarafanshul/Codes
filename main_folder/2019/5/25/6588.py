N=1000000
seive=[1]*(N)
primelist=[]
for i in range(2,N):
    if seive[i]==0:
        continue
    primelist+=[i]
    for j in range(2*i,N,i):
        seive[j]=0

printlist=[]
while 1:
    n=int(input())
    if n==0: break
    for i in primelist:
        if i+i>n: break
        if seive[n-i]==1:
            printlist.append("%d = %d + %d"%(n,i,n-i))
            break
print("\n".join(printlist))
