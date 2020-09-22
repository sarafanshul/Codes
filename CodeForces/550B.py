from itertools import combinations as cmb
n ,l ,r ,x = map(int , input().split())
*a , = map(int ,input().split())
b = []
a.sort()
for i in range(2 ,n+1):
    b.extend(cmb(a ,i))
ans = 0
for i in b:
    # i1 = sorted(i)
    if(sum(i) >= l and sum(i) <= r):
        if(i[-1]-i[0] >= x):
            # print(i)
            ans+=1
            
print(ans)
