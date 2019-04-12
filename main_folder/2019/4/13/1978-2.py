from math import sqrt
cnt=int(input())
a=list(map(int,input().split()))
for i in range(len(a)):
    if a[i]<2:
        cnt-=1
        continue
    else:
        for j in range(2,int(sqrt(a[i]))+1):
            if a[i]%j==0:
                cnt-=1
                break
print(cnt)
