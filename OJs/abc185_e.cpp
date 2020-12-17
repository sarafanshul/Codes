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

ll dp[MAXN][MAXN] = { 0 } ;

void check(){
	ll n ,m;
	cin >> n >> m;
	vector<ll> a(n + 1) ,b(m + 1) ;
	for(ll i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(ll i = 1 ; i <= m ; i++)
		cin >> b[i];

	for(ll i = 0 ; i <= n ; i++){
		for(ll j = 0 ; j <= m ; j++){
			dp[i][j] = max(i ,j) ;
		}
	}
	for(ll k = 2 ; k <= n + m ; k++){
		for(ll i = 1 ; (i <= n && i < k) ; i++){
			if(k - i <= m) {
				ll j = k - i ;
				if( a[i] == b[j] ){
					dp[i][j] = min( {
						dp[i - 1][j - 1] , dp[i][j] ,
						dp[i - 1][j] + 1 ,dp[i][j - 1] + 1
					} ) ;
				}else {
					dp[i][j] = min( {
						dp[i - 1][j - 1] + 1, dp[i][j] ,
						dp[i - 1][j] + 1 ,dp[i][j - 1] + 1
					} ) ;
				}
			}
		}
	}
	cout << dp[n][m] <<'\n';
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
