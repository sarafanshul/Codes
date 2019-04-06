a=input()
list1=[]
sum=0
while len(a)%3 !=0:
    a="0"+a
for i in range(0,len(a)-2,3):
    sum=int(a[i])*(2**2)+int(a[i+1])*(2**1)+int(a[i+2])
    list1.append(str(sum))
print("".join(list1))
