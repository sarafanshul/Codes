n,k=map(int,input().split())
def count(a):
    count2=0
    count5=0
    i=1
    j=1
    while 2**i<=a:
        count2+=a//(2**i)
        i+=1
    while 5**j<=a:
        count5+=a//(5**j)
        j+=1
    return [count2,count5]
print(min(count(n)[0]-count(k)[0]-count(n-k)[0],count(n)[1]-count(k)[1]-count(n-k)[1]))
