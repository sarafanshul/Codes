t=int(input())
totallist=[]
copylist=[]
droplist=[]
for i in range(t):
    n,l,k=map(int,input().split())
    for j in range(n):
        translist=[]
        p,a=map(int,input().split())
        translist.append(p)
        translist.append(a)
        totallist.append(translist)
    copylist=totallist
    while len(droplist) != k:
        for j in range(len(totallist)-1):
            if totallist[j][1]>0 and totallist[j+1][1]<0:
                if totallist[j+1][0]-totallist[j][0]==1:
                    totallist[j][0]+=1
                    totallist[j+1][0]+=1
                    totallist[j][1]*=-1
                    totallist[j+1][1]*=-1
        for i in range(len(totallist)):
            totallist[i][0]-=1
            if totallist[i][0]==0 or totallist[i][0]==30:
                droplist.append(copylist[i][1])
print(droplist)



