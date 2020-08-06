import sys
n = int(sys.stdin.readline())
lst = [0]*10001
list=[]
for i in range(n):
    lst[int(sys.stdin.readline())] += 1

for i in range(len(lst)):
    list+=[i]*lst[i]
for i in range(len(list)):
    print(list[i])

