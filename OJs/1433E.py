x = int(input())
fact = [1 for i in range(100)]
for i in range(1 ,55):
    fact[i] = fact[i-1]*i
ans = []
for i in range(50): 
    ans.append(int(fact[2*i+1]/(i+1)))
print(ans[(x//2)-1])
