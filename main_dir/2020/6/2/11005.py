N,B=map(int,input().split())
list1=[]
while 1:
    A=N//B
    b=N%B
    if A==0:
        list1.insert(0,N)
        break
    else:
        list1.insert(0,b)
    N=N//B
for i in range(len(list1)):
    if list1[i]>=10:
        list1[i]=chr(list1[i]+55)
    else:
        list1[i]=str(list1[i])
print("".join(list1))
