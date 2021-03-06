#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define MAX 100000000000000000
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revrep(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define ii pair<ll,ll>
#define MP make_pair
#define pb push_back
#define f first
#define se second
#define ll long long int
#define vi vector<ll>
ll modexp(ll a,ll b){ ll res = 1; while(b > 0){  if(b & 1) res = (res * a)%mod;  a = (a * a)%mod;  b/=2;  }  return res; }
#define rs resize
typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, 
); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif
 
const ll N = 100009;
ll n,i,seen;
string a[N],b[N];
ll cost[N];
ll dp[2][N];
int main()
{
    std::ios_base::sync_with_stdio(false); cin.tie(NULL);
    rep(i,0,2) rep(n,0,N) dp[i][n] = MAX;
    cin>>n;
    rep(i,1,n + 1) cin>>cost[i];
    rep(i,1,n + 1){
        cin>>b[i];
        a[i] = b[i];
        reverse(all(b[i]));
    }
    dp[0][1] = 0;
    dp[1][1] = cost[1];
    rep(i,2,n + 1){
        //without reverse
        if(a[i] >= a[i - 1])
            dp[0][i] = dp[0][i - 1];
        if(a[i] >= b[i - 1])
            dp[0][i] = min(dp[0][i],dp[1][i - 1]);
        //reverse
        if(b[i] >= a[i - 1])
            dp[1][i] = dp[0][i - 1] + cost[i];
        if(b[i] >= b[i - 1])
            dp[1][i] = min(dp[1][i],dp[1][i - 1] + cost[i]);
    }
    n = min(dp[0][n],dp[1][n]);
    cout<<(n == MAX ? -1 : n);
    return 0;
}
