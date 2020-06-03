list1=[[0]*10,[1,1,1,1,1,1,1,1,1,1,1]]
sum=0
n=int(input())
for i in range(n-1):
    list1.append([0]*10)

for i in range(2,n+1):
    for j in range(0,10):
        for k in range(0,j+1):
            list1[i][j]+=list1[i-1][k]
for i in range(0,10):
    sum+=list1[n][i]
print(sum % 10007)
