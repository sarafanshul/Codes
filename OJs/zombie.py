# for case in range(int(input())):
#     N = int(input())
#     P = [0]*N
#     C = list(map(int , input().split()))
#     H = list(map(int , input().split()))

#     for i in range(N):
#         if (i - C[i] >= 0) and (i + C[i] < N):
#             print('if ',i)
#             for j in range(i-C[i] , i+C[i]+1):
#                 P[j] += 1

#         elif (i - C[i] >= 0) and (i + C[i] > N):
#             print('elif 1 ',i)
#             for j in range(i-C[i] , N):
#                 P[j] += 1

#         elif (i + C[i] < N) and (i - C[i] < 0):
#             print('elif 2 ',i)
#             for j in range(0 , i+C[i]+1):
#                 P[j] += 1
#         else:
#             print('else ',i)
#             for j in range(0,N):
#                 P[j] += 1  
#         print(P)        
#     print(P)
#     if sorted(H) == sorted(P): print('YES')
#     else: print('NO')

#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main() {
    // your code goes here
    fastIO;
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        long long rp[n+1],z[n+1],rl[n+1]={0},z1[n+1];
        for(int i=1;i<=n;i++)
        {
            cin >> rp[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin >> z[i];
            //cout << z[i];
            z1[i]=z[i];
        }
        //cout << z[1] << endl;
        for(int i=1;i<=n;i++)
        {
            //cout << z[1] << endl;
            for(int j=i-rp[i];j<=i+rp[i];j++)
            {
                if((j>=1)&&(j<=n))
                {
                    rl[j]++;
                }
            }
        }
        int count=0;
        sort(z1+1,z1+n+1);
        sort(rl+1,rl+n+1);
        //cout << z[1] << endl;
        
        for(int k=1;k<=n;k++)
        {
            // cout << z1[k] << endl;
            // cout << rl[k] << endl;
            if(z1[k]==rl[k])
            count++;
        }
        //cout << count;
        if(count==n)
        cout << "YES" << endl;
        else
        cout << "NO" << endl;
    }
    
    
    return 0;
}

# # # does not work
# t = int(input())
# for case in range(t):
#     N = int(input())
#     P = [0]*N
#     C = list(map(int , input().split()))
#     H = list(map(int , input().split()))

#     for i in range(1 ,N+1):
#         if (i - C[i-1] >= 0) and (i + C[i-1] < N):
#             for j in range(i-C[i-1] , i+C[i-1]):
#                 P[j-1] += 1

#         elif (i - C[i-1] >= 0) and (i + C[i-1] > N):
#             for j in range(i-C[i-1] , N):
#                 P[j-1] += 1

#         elif (i + C[i-1] < N) and (i - C[i-1] < 0):
#             for j in range(1 , i+C[i-1]):
#                 P[j-1] += 1
#         else:
#             # for j in range(0,N):
#             for j in range(1,N):
#                 P[j-1] += 1  
#     print(P)
#     if sorted(H) == sorted(P): print('YES')
#     else: print('NO')


# # # logic is right but TLE time = 5.5 BEST
# for case in range(int(input())):
#     n = int(input())
#     rp = list(map(int , input().split()))
#     z = list(map(int , input().split()))
#     rl = [0]*n
#     # print(rl)

#     for i in range(1 , n+1):
#         # print('i ' , i)
#         for j in range(i-rp[i-1] , i+rp[i-1]+1):
#         # for j in range(i-rp[i] , i+rp[i]+1):
#             # print('j ' , j)
#             if (j >= 1) and (j <= n):
#                 # print('if ', i,'-',j )
#                 # rl[j] += 1
#                 rl[j-1] += 1
#                 # print(rl)
#     # print(rl)
#     Res = sorted(rl)
#     z1 = sorted(z)
#     if Res==z1 : print('YES')
#     else: print('NO')

# # # 8.5 secs + TLE
# for case in range(int(input())):
#     n = int(input())
#     # not using map function
#     # rp = list(map(int , input().split()))
#     rp = input().split()
    
#     rl = [0]*n

#     for i in range(1 , n+1):
#         for j in range(i-int(rp[i-1]) , i+int(rp[i-1])+1):            
#             if (j >= 1) and (j <= n):
#                 # rl[j-1] += 1
#                 rl[j-1] = int(rl[j-1]) + 1

#     z = list(map(int , input().split()))
#     if sorted(rl)==sorted(z) : print('YES')
#     else: print('NO')



# # #  logic is right but TLE , time = 5.5 BEST
# # # copied from above
# t = int(input())
# for case in range(t):
#     n = int(input())
#     rp = list(map(int , input().split()))
#     z = list(map(int , input().split()))
#     rl = [0]*n
#     # print(rl)

# # main logic brute forced
#     for i in range(1 , n+1):
#         if ((i-rp[i-1]) < 1): # WRONG
#             pass
#         else:
#             for j in range(i-rp[i-1] , i+rp[i-1]+1):
#                 if (j >= 1) and (j <= n):
#                     rl[j-1] += 1
#                     # print(rl)

#     # print(rl)

#     Res = sorted(rl)
#     z1 = sorted(z)
#     if Res==z1 : print('YES')
#     else: print('NO')


# # # logic is not right but TLE time = 9.5 
# def zom(n,rp):
    
#     return rl


# # # best time = 5.45 sec 
# for case in range(int(input())):
#     n = int(input())
#     rp = list(map(int , input().split()))
#     z = list(map(int , input().split()))

#     mi = min(rp)
#     if  mi >= n:
#         rl = [n]*n
    
#     else:
#         rl = [0]*n
#         for i in range(1 , n+1):           
#             for j in range(i-rp[i-1] , i+rp[i-1]+1):
#                 if (j >= 1) and (j <= n):    
#                     rl[j-1] += 1

#     Res = sorted(rl)
#     z1 = sorted(z)
#     if Res==z1 : print('YES')
#     else: print('NO')

# # # # 0.48 sec with PyPy3 but low tl for pypy3
# for case in range(int(input())):
#     n = int(input())
#     rp = list(map(int , input().split()))
#     z = list(map(int , input().split()))
    
#     mi = min(rp)
#     if  mi >= n:
#         rl = [n]*n
    
#     else:
#         rl = [0]*n
#         for i in range(1 , n+1):           
#             for j in range(i-rp[i-1] , i+rp[i-1]+1):
#                 if (j >= 1) and (j <= n):    
#                     rl[j-1] += 1

#     Res = sorted(rl)
#     z1 = sorted(z)
#     if Res==z1 : print('YES')
#     else: print('NO')


# # # slow compared to bellow
# for case in range(int(input())):
#     n = int(input())
#     *rp , = map(int , input().split())
#     # z = list(map(int , input().split()))
#     *z , = map(int , input().split())
    
#     mi = min(rp)
#     if  mi >= n:
#         rl = [n]*n
    
#     else:
#         rl = [0]*n
#         for i in range(1 , n+1):           
#             for j in range(i-rp[i-1] , i+rp[i-1]+1):
#                 if (j >= 1) and (j <= n):    
#                     rl[j-1] += 1

#     Res = sorted(rl)
#     z1 = sorted(z)
#     if Res==z1 : print('YES')
#     else: print('NO')


# # # FASTER 6secs
# def zom(n,rp):
#     rl = [0]*n
#     for i in range(1 , n+1):
#         # print('i ' , i)
#         for j in range(i-rp[i-1] , i+rp[i-1]+1):
#             # print('j ' , j)
#             if (j >= 1) and (j <= n):
#                 # print('if ', i,'-',j )
#                 rl[j-1] += 1
#     return rl

# for case in range(int(input())):
#     n = int(input())
#     rp = list(map(int , input().split()))
#     z = list(map(int , input().split()))
#     z=sorted(z)
#     mi = min(rp)

#     if mi >= n and z[0] == n:
#         Res = [n]*n
#     else:
#         Res = sorted(zom(n , rp))

#     if Res==z : print('YES')
#     else: print('NO')

# # # time = 5.8sec
# def zom(n,rp):
#     rl = [0]*n
#     for i in range(1 , n+1):
#         for j in range(i-rp[i-1] , i+rp[i-1]+1):
#             if (j >= 1) and (j <= n):
#                 rl[j-1] += 1
#     return rl

# if __name__ == '__main__':
#     for case in range(int(input())):
#         n = int(input())
#         rp = list(map(int , input().split()))
#         z = set(map(int , input().split()))
#         mi = min(rp)

#         if mi >= n :
#             Res = [n]*n
#         else:
#             Res = zom(n , rp)
 
#         if set(Res) == set(z) : print('YES')
#         else: print('NO')


# # # # ------------AC WORKS FINE----------


# def prefsum(arr):
#     for i in range(1,len(arr)):
#         arr[i] = arr[i]+arr[i-1]
#     arr.pop()
#     del arr[0]
#     return arr
# for _t in range(int(input())):
#     n = int(input())
#     c = list(map(int, input().split()))
#     h = list(map(int, input().split()))
#     radLevel = [0 for i in range(n+2)]
#     lm = len(radLevel)
#     for i in range(0,n):
#         radLevel[max(1,i+1-c[i])] += 1
#         radLevel[min(i+1+c[i]+1, n+1)] -= 1

#     radLevel = prefsum(radLevel)
#     if sorted(h) == sorted(radLevel):
#         print("YES")
#     else:
#         print("NO")

# # ---------final complete--------------

def ZomRad(arr):
    for i in range(1 , len(arr)):
        arr[i] = arr[i] + arr[i-1]
    arr.pop()
    del arr[0]
    return arr
for _t in range(int(input())):
    n = int(input())
    c = list(map(int , input().split()))
    h = list(map(int , input().split()))
    # rLevel = [0 for i in range(n+2)]
    rLevel = [0]*(n+2)
    lm = len(rLevel)
    
    for i in range(0 , n):
        rLevel[max(1 , i+1-c[i])] += 1
        rLevel[min(i+1+c[i]+1 , n+1)] -= 1
    # print(rLevel)
    rLevel = ZomRad(rLevel)
    
    # print(rLevel)
    if sorted(h) == sorted(rLevel): print('YES')
    else: print('NO')