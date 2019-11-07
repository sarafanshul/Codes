list2=[]
list=[[0 for i in range(10001)] for i in range(10001)]
list[0][0]=1
list[1][0]=1
for i in range(1,100):
    list[i][i]=1
    list[i][0]=1
    for j in range(1,100):
        list[i][j]=(list[i-1][j-1]+list[i-1][j])
while 1:
    n,k=map(int,input().split())
    if(n==0 and k==0):
        break
    if(list[n][k]>2**31):
        continue
    list2.append(list[n][k])
for j in range(len(list2)):
    print(list2[j])
