a=[]
sum=0
for i in range(5):
    a=a+[int(input())]
    if a[i]<40:
        a[i]=40
    sum+=a[i]
print(int(sum/5))

