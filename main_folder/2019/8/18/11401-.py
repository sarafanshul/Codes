n,k=map(int,input().split())
a=1
b=1
c=1
mod=1000000007
for i in range(1,k+1):
    b*=i
for j in range(1,n+1):
    a*=j
for z in range(1,n-k+1):
    c*=z
a%=mod
b%=mod
c%=mod
print(a*(b**(mod-2)*(c**(mod-2)))%mod)
