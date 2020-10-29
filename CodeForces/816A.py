h,m=map(int,input().split(':'))
i=0
while h//10!=m%10 or h%10!=m//10:
    i+=1
    m+=1
    if m==60:
        h+=1
        h=h%24
        m=0
print(i)
