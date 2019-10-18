a,b,c=map(int,input().split())
list1=[a,b,c]
list1=sorted(list1)
if list1[1]-list1[0] == list1[2]-list1[1]:
    print(list1[2]+list1[2]-list1[1])
elif (list1[2]-list1[1])//(list1[1]-list1[0])==2:
    print(list1[1]+list1[1]-list1[0])
else:
    print(list1[1]-(list1[2]-list1[1]))
