# https://www.codechef.com/LTIME74B/problems/SFRV/

def find_max_sum(arr): 
    incl = 0
    excl = 0
     
    for i in arr: 
          
        # Current max excluding i (No ternary in  
        # Python) 
        new_excl = excl if excl>incl else incl 
         
        # Current max including i 
        incl = excl + i 
        excl = new_excl 
      
    # return max of incl and excl 
    return (excl if excl>incl else incl)
t=int(input())
for _ in range(t):
    n=int(input())
    a=list(map(int,input().split(" ")))
    z=a[0]
    b=[]
    for i in range(1,n):
        z+=a[i]*(i+1)
        b.append(a[i-1]-a[i])
    s=z+find_max_sum(b)
    print(s)

# ------------------------------------------------------------------

for _ in range(int(input())):
    n=int(input())
    it=list(map(int,input().split()))
    dp=[[-1,-1] for i in range (n+1)]
    dp[0]=[0,0]
    
    dp[1]=[it[0]*1,0]
    
    for i in range(2,n+1):
        dp[i][1]=max(dp[i-2])+it[i-1]*(i-1)+it[i-2]*(i)
        dp[i][0]=max(dp[i-1])+it[i-1]*(i)
    print(max(dp[n]))
