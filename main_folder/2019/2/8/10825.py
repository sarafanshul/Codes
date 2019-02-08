import sys
n=int(input())
list1=[]
for _ in range(n):
    q,w,e,r=map(str,sys.stdin.readline().split())
    list1.append([int(w)*-1,int(e),int(r)*-1,q])
list2=sorted(list1)
for i in range(n):
    print(list2[i][3])
