list2=[]
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if a==b and b==c:
        list2.append(10000+a*1000)
    if a==b and b != c:
        list2.append(1000+a*100)
    if a==c and a != b:
        list2.append(1000+a*100)
    if b==c and a != b:
        list2.append(1000+b*100)
    if a != b and b != c:
        list2.append(max(a,b,c)*100)
print(max(list2))
