case=int(input())
list=[]
list2=[]
for z in range(case):
    h,w=map(int,input().split())
    for i in range(h):
        list.append(input())
        list2.append(list[i][::-1])
for i in range(len(list2)):
    print(list2[i])
