list1=[1,1]
n=int(input())
if n<=2:
    print(list1[n-1])
else:
    for i in range(2,n):
        list1.append(list1[i-1]+list1[i-2])
    print(list1[-1])
