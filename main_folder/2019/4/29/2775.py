a=int(input())

list=[[0]*15 for i in range(15)]
list2=[]
for c in range(15):
    list[c][0]=1

for i in range(15):
    list[0][i]=i+1

for j in range(1,15):
    for k in range(1,15):
        list[j][k]=list[j-1][k]+list[j][k-1]

for z in range(a):
    b=int(input())
    c=int(input())
    list2+=[list[b][c-1]]

for k in range(len(list2)):
    print(list2[k])
