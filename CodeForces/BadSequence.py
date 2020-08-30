from collections import Counter

n = int(input())
bra = input()

d=Counter(bra)
ans=0
if d['(']==d[')']:
    c=0
    for i in bra:
        if i=='(':
            c+=1
        else:
            if c==0:
                ans+=1
            else:
                c-=1
    if ans<=1:
        print('Yes')
    else:
        print('No')
else:
    print('No')