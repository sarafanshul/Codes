def ct(i):
    count=0
    for input in range(1,i+1):
        if(input<100):count+=1
        elif(input<1000):count+=func100(input)
        else:pass
    return count
def func100(num):
    h,t,o=str(num)[0],str(num)[1],str(num)[2]
    h,t,o=int(h),int(t),int(o)
    if h-t==t-o:
        return 1
    else:
        return 0
n=int(input())
print(ct(n))
