list=[]
count=0
for i in range(4):
    a,b=map(int,input().split())
    count=count-a+b
    list.append(count)
print(max(list))
