a=int(input())
list=[]
for i in range(a):
    list+=[int(input())]
b=sorted(list)
for i in range(len(b)):
    print(b[i])
