n = int(input())
a* , = map(int , input().split())
m = input()
m1 = sum((1<<i for i in range(len(m)) if(m[i] == '1') ))
ans = 0
for i in range(m1+1):
    bi = bin(i)[2:][::-1]
    tmp = 0
    for j in range(len(bi)):
        if(bi[j] == '1'): tmp += a[j]
    ans = max(ans ,tmp)
print(ans)
