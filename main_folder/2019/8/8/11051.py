n,k=map(int,input().split())
list=[[0 for i in range(1001)] for i in range(1001)]
list[0][0]=1
list[1][0]=1
for i in range(1,n+1):
    list[i][i]=1
    list[i][0]=1
    for j in range(1,n):
        list[i][j]=(list[i-1][j-1]+list[i-1][j])%10007
print(list[n][k])
