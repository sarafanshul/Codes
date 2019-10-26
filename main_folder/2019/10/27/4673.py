setA = {i for i in range(1, 10001)}
setB = set()
for i in range(1, 10001):
    for j in str(i):
        i += int(j)
    setB.add(i)

setA = sorted(setA-setB)
for i in setA:
    print(i)
