from sys import stdin
a=int(input())
list=[]
for i in range(a):
    list.append(int(stdin.readline()))
list.sort()
for i in range(len(list)):
    print(list[i])

