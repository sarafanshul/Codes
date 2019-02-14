list=[]
for i in range(int(input())):
    a,b=map(int,input().split(","))
    list.append(a+b)
for j in range(len(list)):
    print(list[j])
