list1=list(map(int,input().split()))
sum=0
for i in range(len(list1)):
    sum+=list1[i]**2
print(sum%10)
