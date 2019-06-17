import time
start = time.time()
def sosu(n):
    for i in range(2,n):
        if n%i == 0:
            return 0
    return 1
count = 0
for i in range(2,1000000):
    if sosu(i):
        count+=1
        if count == 10001:
            print(i)
end = time.time() - start
print(end)
