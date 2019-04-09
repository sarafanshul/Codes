n=int(input())
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
    return min(count2,count5)
print(count(n))
