import sys
list1=[]
N=int(input())
for _ in range(N):
    n,k=map(str,sys.stdin.readline().split())
    list1.append([int(n),k])
list2=sorted(list1,key=lambda x:x[0])
for i in range(N):
    print("%d %s"%(list2[i][0],list2[i][1]))
