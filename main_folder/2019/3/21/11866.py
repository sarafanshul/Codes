import sys
n,m=map(int,sys.stdin.readline().split())
queue=list(range(1,n+1))
list1=[]
for z in range(n):
   index=(m-1)%len(queue)
   list1.append(str(queue[index]))
   queue=queue[index+1:]+queue[:index]
print("<"+", ".join(list1)+">")
