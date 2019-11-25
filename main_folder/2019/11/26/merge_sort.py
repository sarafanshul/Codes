import random
def merge_sort(a):
    n=len(a)
    if n<=1:
        return a
    mid=n//2
    g1=merge_sort(a[:mid])
    g2=merge_sort(a[mid:])
    result=[]
    while g1 and g2:
        if g1[0]<g2[0]:
            result.append(g1.pop(0))
        else:
            result.append(g2.pop(0))
    while g1:
        result.append(g1.pop(0))
    while g2:
        result.append(g2.pop(0))
    return result
a=int(input())
list=[]
for i in range(a):
    list.append(random.randint(1,1000000))
sortlist2=merge_sort(list)
for j in range(len(sortlist2)):
    print(sortlist2[j])

