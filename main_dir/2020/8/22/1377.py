L=[(int(input()),i) for i in range(int(input()))]
L.sort()
m=0
for i in range(len(L)):
    m=max(L[i][1]-i,m)
print(m+1)
