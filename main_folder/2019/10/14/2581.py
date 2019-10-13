def sieve(n):
    if n < 2:
        return []
    s = [0, 0] + [1] * (n - 1)
    for i in range(2, int(n**0.5)+1):
        if s[i]:
            s[i*2::i] = [0] * ((n - i)//i)
    return [i for i, v in enumerate(s) if v]
sum=0
a=int(input())
b=int(input())
a=set(sieve(a-1))  #a-1 까지의 소수 개수
b=set(sieve(b))    #b까지 소수 개수
c=sorted(list(b-a))
for i in range(len(c)):
    sum+=c[i]
if sum==0:
    print("-1")
else:
    print(sum)
    print(min(c))
