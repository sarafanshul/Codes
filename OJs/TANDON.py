# '1200'[::-1].lstrip('0')
MOD = 1e9+7
for case in range(int(input())):
    N , K = map(int , input().split())
    mx = 10**N

    maxrev = 0
    ans = 0 

    for i in range(mx,0,-K):
        if i == mx : continue
        if i == maxrev: break

        rev = int(str(i)[::-1])
        maxrev = max(rev , maxrev)

        if rev < mx and rev%K == 0: ans += 1
        if rev < i and rev%K == 0: ans += 1
    
    print(int((ans+1)%MOD))


