a,b=map(int,input().split())
pib=[0,1]
for i in range(a%1500000-1):
    pib.append((pib[i]+pib[i+1])%1000000007)
for j in range(b%1500000-1):
    pib.append((pib[j]+pib[i+1])%1000000007)
print(pib[a%1500000])
print(pib[b%1500000])
