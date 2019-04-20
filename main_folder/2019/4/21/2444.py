list1=[]
a=int(input())
for i in range(a):
    b=" "*(a-i-1)+"*"*(2*(i+1)-1)
    list1.append(b)
for i in range(a):
    print(list1[i])
for i in range(a-2,-1,-1):
    print(list1[i])
