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

const long long MAXN = 1e3 +7;
const long long MOD = 1e9 + 7;


ll dp[MAXN][MAXN];
string a[MAXN];
ll n ,m;

void check(){
	cin >> n >> m;
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
	}
	dp[0][0] = 1;
	for(ll i = 1 ; i < n ; i++) if(a[i][0] != '#') dp[i][0] = dp[i-1][0];
	for(ll i = 1 ; i < m ; i++) if(a[0][i] != '#') dp[0][i] = dp[0][i-1];

	for(ll i = 1 ; i < n ; i++){
		for(ll j = 1 ; j < m ; j++){
			if(a[i][j] != '#') dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
		}
	}
	cout << dp[n-1][m-1]<< '\n' ;
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
