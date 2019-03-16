a=int(input())
list1=[1,2]
if a<2:
    print(list1[a-1])
else:
    for i in range(2,a):
        list1.append((list1[i-1]+list1[i-2])%10007)
    print(list1[-1])
