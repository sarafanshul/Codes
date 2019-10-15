a=int(input())
pib=[0,1]
for i in range(a%1500000-1):
    pib.append((pib[i]+pib[i+1])%1000000)
print(pib[a%1500000])
