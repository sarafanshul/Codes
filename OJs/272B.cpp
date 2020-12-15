#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
 
#include <bits/stdc++.h>
 
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
using namespace std;
 
const ll N = 101LL;
 
ll n ,m ,val = 0;
string s1 ,s2;
int dp[N][N];
 
inline bool valid(ll i ,ll j) {return i >= 1 && i <= n && j >= 1 && j <= m; }
 
int solve(int s,int l,int f) {
    int &ret=dp[s][l];
    if(s==l) {
        if(f==val) return 1;
        else return 0;
    }
   
    int ct=0;
    if(s2[s]=='+')
        ct+=solve(s+1,l,f+1);
    if(s2[s]=='-')
        ct+=solve(s+1,l,f-1);
    if(s2[s]=='?')
        ct+=solve(s+1,l,f+1)+solve(s+1,l,f-1);
    return ret=ct;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	double ans;
    cin>>s1>>s2;
    n=s1.size();
    for(int i=0;i<n;i++) {
        if(s1[i]=='+') val++;
        else val--;
    }
 
    double xx=1;
    for(int i=0;i<n;i++){
       if(s2[i]=='?')
       xx*=2.0;
    }
 
    int k=solve(0,s2.size(),0);
    // cout << k;
    if (!k) cout << setprecision(10) << (double)k;
    else cout << setprecision(10) << ((double)k)/xx;
	return 0;
}
 