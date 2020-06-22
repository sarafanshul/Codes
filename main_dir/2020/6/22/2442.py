list=[]
a=int(input())
for i in range(1,a+1):
    list.append(" "*(a-i)+"*"*(2*i-1))
for j in range(len(list)):
    print(list[j])
