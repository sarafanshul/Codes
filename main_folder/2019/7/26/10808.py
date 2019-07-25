list1=[0 for i in range(26)]
a=input()
for i in range(len(a)):
    list1[ord(a[i])-97]+=1
for i in range(len(list1)):
    print(list1[i],end=" ")
