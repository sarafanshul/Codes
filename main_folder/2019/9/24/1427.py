a=input()
list=[]
for i in range(len(a)):
    list+=[int(a[i])]
b=sorted(list)
for j in range(len(b)-1,-1,-1):
    print(b[j],end="")
