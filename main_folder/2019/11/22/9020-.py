def sieve(n):
    if n < 2:
        return []
    s = [0, 0] + [1] * (n - 1)
    for i in range(2, int(n**0.5)+1):
        if s[i]:
            s[i*2::i] = [0] * ((n - i)//i)
    return [i for i, v in enumerate(s) if v]

a=int(input())

list2=[]
new_list=[]
for z in range(a):
    list=[]
    b=int(input())
    c=sieve(b)

    for i in range(len(c)):
        for j in range(i,len(c)):
            if c[i]+c[j]==b:
                list+=[c[i],c[j]]
                continue
    if len(list)==2:
        list2+=[list]
    else:
        for q in range(0,len(list)-1,2):
            new_list+=[list[q+1]-list[q]]
print(new_list)
