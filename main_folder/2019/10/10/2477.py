k = int(input())
list1 = [int(input().split()[1]) for x in range(6)]
a = list1.index(max(list1))
if list1[(a-1)%6] > list1[(a+1)%6]:
    b=(a-1)%6
else:
    b=(a+1)%6

c = (a+3)%6
d = (b+3)%6
print(k * (list1[a]*list1[b] - list1[c]*list1[d]))
