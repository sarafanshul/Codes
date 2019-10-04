import sys
podo = []
x = int(input())
pd = list(map(int, sys.stdin.readlines()))
pd.insert(0, 0)
podo.append(pd[0])
podo.append(pd[0]+pd[1])
if(x > 1):
    podo.append(pd[0]+pd[1]+pd[2])
for i in range(3, x+1):
    podo.append(max(podo[i-1], podo[i-2]+pd[i], podo[i-3]+pd[i]+pd[i-1]))
print(podo[x])
