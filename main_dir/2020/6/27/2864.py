a,b=map(str,input().split())
c=a
d=b
for i in range(len(a)):
    if a[i]=='6':
        a=a[:i]+"5"+a[i+1:]
for j in range(len(b)):
    if b[j]=='6':
        b=b[:j]+"5"+b[j+1:]
for i in range(len(a)):
    if c[i]=='5':
        c=c[:i]+"6"+c[i+1:]
for j in range(len(b)):
    if d[j]=='5':
        d=d[:j]+"6"+d[j+1:]
print(int(a)+int(b), int(c)+int(d))

