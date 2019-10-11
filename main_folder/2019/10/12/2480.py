a,b,c=map(int,input().split())
if a==b and b==c:
    print(10000+a*1000)
if a==b and b != c:
    print(1000+a*100)
if b==c and a != b:
    print(1000+b*100)
if a==c and a != b:
    print(1000+a*100)
if a != b and b!= c and a != c:
    print(max(a,b,c)*100)
