def sieve(n):
    if n < 2:
        return []
    s = [0, 0] + [1] * (n - 1)
    for i in range(2, int(n**0.5)+1):
        if s[i]:
            s[i*2::i] = [0] * ((n - i)//i)
    return [i for i, v in enumerate(s) if v]

a,b=map(int,input().split())
a=set(sieve(a-1))
b=set(sieve(b))
c=sorted(list(b-a))
for i in range(len(c)):
    print(c[i])
