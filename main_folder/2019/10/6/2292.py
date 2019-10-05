a=int(input())
if a==1:
    print(1)
for i in range(2,18259):
    if a>=((3*(i-1)*(i-1))-(3*(i-1))+2) and a<=(3 * i*i) - (3 * i) + 1:
        print(i)
        break
