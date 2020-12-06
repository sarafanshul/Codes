#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define pii pair<ll,ll>
#define f first
#define s second
#define pb push_back

ll M = 1e9+7;
 
ll p2(ll a,ll b,ll m)
{
    ll res=0;
    a %= m;
    while(b)
    {
        if(b%2) res = (res+a)%m;
        a = (a+a)%m;
        b /= 2;
    }
    return res;
}
 
ll p1(ll a,ll b,ll m)
{
    ll res = 1;
    a %= m;
    while(b)
    {
        if(b%2)res = p2(res,a,m);
        a = p2(a,a,m);
        b /= 2;
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b>>n;
        ll ans;
        if(a-b)
        {
            ans = (p1(a,n,a-b) + p1(b,n,a-b) )%(a-b);
            ans = __gcd(ans,a-b);    
        }
        else
        {
            ans = (2*p1(a,n,M))%M;
        }
        cout<<ans%M<<"\n";
    }
} 
