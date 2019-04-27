from sys import stdin
def quick_sort(a):
    n=len(a)
    if n<=1:
        return a
    standard=a[-1]
    g1=[]
    g2=[]
    for i in range(0,n-1):
        if a[i]<standard:
            g1.append(a[i])
        else:
            g2.append(a[i])

    return quick_sort(g1)+[standard]+quick_sort(g2)
a=int(input())
list=[]
for i in range(a):
    list.append(int(stdin.readline()))
list2=quick_sort(list)
for i in range(len(list2)):
    print(list2[i])

