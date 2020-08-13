A=int(input())
a=sorted(list(map(int,input().split())))
b=sorted(list(map(int,input().split())))
b=b[::-1]
sum=0
for i in range(len(a)):
    sum+=a[i]*b[i]
print(sum)

