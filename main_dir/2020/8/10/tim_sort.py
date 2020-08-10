import time
start = time.time()
import random

a=int(input())
list=[]
for i in range(a):
    list.append(random.randint(1,1000000))
list.sort()
for i in range(len(list)):
    print(list[i])


end = time.time() - start
print(end)

