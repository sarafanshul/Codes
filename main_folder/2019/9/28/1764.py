import sys
n,m=map(int,input().split())
lista=[]
listb=[]
for i in range(n):
    lista.append(sys.stdin.readline())
for j in range(m):
    listb.append(sys.stdin.readline())
lista=set(lista)
listb=set(listb)
listc=sorted(list(lista&listb))
print(len(listc))
for i in range(len(listc)):
    print(listc[i],end="")
