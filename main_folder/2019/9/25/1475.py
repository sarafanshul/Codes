a=input()
total=[0 for i in range(10)]
for i in range(10):
    for j in range(len(a)):
        if int(a[j])==i:
            total[i]+=1
total[6]=total[6]+total[9]

if total[6]%2==0:
    total[6]=total[6]/2
else:
    total[6]=total[6]/2+1
max=0
for i in range(9):
    if max< total[i]:
        max=total[i]
print(int(max))


