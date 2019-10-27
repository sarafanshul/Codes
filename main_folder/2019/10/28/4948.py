def sieve(n):
    if n < 2:
        return []
    s = [0, 0] + [1] * (n - 1)
    for i in range(2, int(n**0.5)+1):
        if s[i]:
            s[i*2::i] = [0] * ((n - i)//i)
    return [i for i, v in enumerate(s) if v]
b=[]
while 1:
    n=int(input())
    if n==0:
        break
    c=len(sieve(2*n))-len(sieve(n))
    b=b+[c]
for i in range(len(b)):
    print(b[i])

