from sys import stdin
MAX_NUM=10000
a=int(input())
A=[]
for i in range(a):
    A.append(int(stdin.readline()))
N=len(A)
count=[0]*(MAX_NUM+1)
countSum=[0]*(MAX_NUM+1)

for i in range(0,N):
    count[A[i]]+=1
countSum[0]=count[0]
for i in range(1,MAX_NUM+1):
    countSum[i]=countSum[i-1]+count[i];

B=[0]*(N+1)

for i in range(N-1,-1,-1):
    B[countSum[A[i]]]=A[i]
    countSum[A[i]]-=1

result=[]
for i in range(1,N+1):
    result.append(str(B[i]))

for i in range(len(result)):
    print(result[i])
