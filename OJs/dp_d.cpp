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

const long long MAXN = 1e5 +7;

ll n , dp[101][MAXN] ,W;
void check(){
	cin >> n >> W;

	pair<ll ,ll> a[101];
	
	for(ll i = 0 ; i < n ; i++){
		cin >> a[i].F >> a[i].S;
	}
	sort(a ,a+n);
	
	for(ll i = 0 ; i <= n ; i++){
		for(ll w = 0 ; w <= W ; w++){
			if(i == 0 || w == 0) dp[i][w] = 0;
			else if( w - a[i-1].F >= 0 ){
				dp[i][w] = max( dp[i - 1][w] ,
					dp[i - 1][w - a[i - 1].F] + a[i - 1].S );
			}else{
				dp[i][w] = dp[i-1][w];
			}
		}
	}

	cout << dp[n][W] <<'\n';
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
