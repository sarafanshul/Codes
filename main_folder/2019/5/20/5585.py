a=1000-int(input())
count=0
while 1:
    if a>=500:
        count+=1
        a-=500
    elif a>=100 and a<500:
        count+=a//100
        a=a-(100*(a//100))
    elif a>=50 and a<100:
        count+=a//50
        a=a-(50*(a//50))
    elif a>=10 and a<50:
        count+=a//10
        a=a-(10*(a//10))
    elif a>=5 and a<10:
        count+=a//5
        a=a-(5*(a//5))
    else:
        count+=a
        break
print(count)
