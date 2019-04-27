a=int(input())
pib=[0,1]
for i in range(a-1):
    pib.append(pib[i]+pib[i+1])
print(max(pib))
