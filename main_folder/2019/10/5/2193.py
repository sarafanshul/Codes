list1=[1,1,2,3]
n=int(input())
if n<=4:
    print(list1[n-1])
else:
    for i in range(5,n+1):
        sum=0
        for j in range(0,i-2):
            sum+=list1[j]
        list1.append(sum+1)
    print(list1[-1])
