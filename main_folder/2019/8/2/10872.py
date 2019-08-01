a=int(input())
b=1
count=0
d=0
for i in range(1,a+1):
    b=b*i
c=str(b)

for j in range(len(c)-1,0,-1):
    if c[j]=="0":
        d=j
        break

for k in range(d,0,-1):
    if c[k]=="0":
        count+=1
    else:
        break
        
print(count)
