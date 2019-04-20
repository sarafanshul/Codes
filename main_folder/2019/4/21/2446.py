list=[]
a=int(input())
for i in range(1,a+1):
    list.append(" "*(i-1)+"*"*((2*a)-(2*i-1)))
for j in range(len(list)):
    print(list[j])
for z in range(len(list)-2,-1,-1):
    print(list[z])
