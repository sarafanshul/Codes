import math
import sys
a=int(sys.stdin.readline())
list1=[int(sys.stdin.readline()) for i in range(a)]
list1=sorted(list1)
list2=[]
list3=[]

def gcd(a,b):
    while(b != 0):
        if(a<b):
            (a,b)=(b,a)
        temp=a%b
        a=b
        b=temp
    return a

for j in range(len(list1)-1):
    list1[j]=list1[j+1]-list1[j]
del list1[len(list1)-1]


for k in range(len(list1)-1):
    for z in range(len(list1)-1):
        list2=list1
        A=list2[z]
        B=list2[z+1]
        list1[z]=gcd(A,B)
    del list1[len(list1)-1]

z=int(math.sqrt(list1[0]))
for i in range(1,z+1):
    if list1[0]%i==0:
        list3.append(i)
        list3.append(list1[0]//i)
del list3[0]
zip=set(list3)
list4=sorted(list(zip))
for z in range(len(list4)):
    print(list4[z],end=" ")
