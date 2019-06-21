N=int(input())
seive=[1]*(N)
prime=[]
for i in range(2,N):
    if seive[i]==0:
        continue
    prime+=[i]
    for j in range(2*i,N,i):
        seive[j]=0
print(prime)
