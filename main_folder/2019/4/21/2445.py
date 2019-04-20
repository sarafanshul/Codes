a=int(input())
list=[]
for i in range(1,a+1):
    list.append("*"*i+" "*((a-i)*2)+"*"*i)
for j in range(len(list)):
    print(list[j])
for z in range(len(list)-2,-1,-1):
    print(list[z])
