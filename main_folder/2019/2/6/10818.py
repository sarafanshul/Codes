a=int(input())
list=[]
list2=[]
list+=(input().split())
for i in range(len(list)):
    list2.append(int(list[i]))
print(min(list2), max(list2))
