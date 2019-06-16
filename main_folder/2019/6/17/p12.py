import time
start = time.time()
a=[]
b,sum,count=1,0,0
while 1:
    for j in range(1,b+1):
        sum+=b
        a=a+[sum]
        b+=1
        for k in range(1,a[j-1]+1):
            count=0
            if a[j-1]%k==0:
                count+=1
                if count==500:
                    print(a[j])
                    break
end = time.time() - start
print(end)
