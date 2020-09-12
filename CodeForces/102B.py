n = input()
it = 0
while(len(n) > 1):
    n1 = 0
    for i in n: n1 += int(i)
    n = str(n1)
    it+=1
print(it)