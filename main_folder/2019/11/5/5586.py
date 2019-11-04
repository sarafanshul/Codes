a=input()
joi=0
ioi=0
for i in range(len(a)-2):
    if a[i]+a[i+1]+a[i+2]=='JOI':
        joi+=1
    elif a[i]+a[i+1]+a[i+2]=='IOI':
        ioi+=1
print(joi)
print(ioi)
