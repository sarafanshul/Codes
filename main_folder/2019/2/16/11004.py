import sys
def quick_sort(a,k):
    n=len(a)
    if n<=1:
        return a
    standard=a[0]
    g1=[a for a in a[1:] if a<=standard]
    g2=[a for a in a[1:] if a> standard]
    if len(g1)>=k:
        return quick_sort(g1,k)
    elif len(g1)==k-1:
        return [standard]
    else:
        return quick_sort(g2,k-len(g1)-1)

n,k=map(int,input().split())
list1=[i for i in sys.stdin.readline().strip().split()]
print(quick_sort(list1,k)[0])
