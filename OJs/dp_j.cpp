#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

const long long MAXN = 307LL;

double dp[MAXN][MAXN][MAXN];
ll n;

double dfs(ll a ,ll b ,ll c){
	if(a + b + c == 0) return 0.0 ;
	if( dp[a][b][c] > -0.5 ) return dp[a][b][c] ;

	double ks = (double)n / (a + b + c);
	double ret = 0;

	if(a){
		ret += (dfs(a - 1 ,b ,c) + ks) * a/(a+b+c);
	}
	if(b){
		ret += (dfs(a + 1 ,b - 1 ,c) + ks) * b/(a+b+c);
	}
	if(c){
		ret += (dfs(a ,b + 1 ,c - 1) + ks) * c/(a+b+c);
	}

	return dp[a][b][c] = ret ;
}

void check(){
	ll t;
	cin >> n;
	ll a[4] = {0} ;
	for(ll i = 0 ; i < n ; i++)	{
		cin >> t;
		a[t]++;
	}
	for(ll i = 0 ; i <= n ; i++) 
		for(ll j = 0 ; j <= n ; j++)
			for(ll k = 0 ; k <= n ; k++)
				dp[i][j][k] = -1;

	double ans = dfs( a[1] ,a[2] ,a[3] ) ;
	cout << fixed << setprecision(9) << ans <<'\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
