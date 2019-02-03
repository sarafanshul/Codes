a=input()
list1=[-1 for i in range(26)]
for i in range(len(a)):
    if list1[ord(a[i])-97] == -1:
        list1[ord(a[i])-97]=i
for i in range(len(list1)):
    print(list1[i],end=" ")
