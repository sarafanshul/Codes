import time
start = time.time()
for a in range(1001):
    for b in range(1001):
        c=1000-a-b
        if c*c==a*a+b*b:
            if a<b and b<c:
                print(a*b*c)
end = time.time() - start
print(end)
