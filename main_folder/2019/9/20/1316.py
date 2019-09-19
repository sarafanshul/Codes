a = int(input())
count = a
for i in range(a):
    b = list(input())
    c = []
    for z in b:
        print(z)
        if z in c:
            if c[-1] != z:
                count -= 1
                break
        c.append(z)
    c.clear()
print(count)
