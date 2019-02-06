from itertools import permutations
a=int(input())
c=list(map(int,input().split()))
list2=[]
list1=permutations(c)
for i in list1:
    sum=0
    for j in range(len(c)-1):
        z=i[j+1]-i[j]
        if z<0:
            z=-z
        sum+=z
    list2.append(sum)
print(max(list2))
