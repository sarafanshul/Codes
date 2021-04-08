#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
using ll = long long ;
using db = long double ; // or double, if TL is tight
template< class T , size_t SZ> using ar = std::array<T , SZ> ; 
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
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
const long long MAXN = 2e5 +7;

void check(){
	ll n , k ;
	cin >> n >> k ;

	vector<ll> store[5] ;
	for( ll i = 1 ; i <= n ; i++ ){
		ll t , a, b ; cin >> t >> a >> b ;
		store[ a*2 + b ].PB( t ) ;
	}
	for( ll i = 0 ; i <= 3 ; i++ ){
		store[ i ].PB( 0 ) ;
		sort( ALL( store[i] ) ) ;
		for( ll j = 1 ; j < store[i].size() ; j++ )
			store[ i ][j] += store[ i ][ j - 1 ] ; 
	}
	ll ans = -1 ;
	for( ll i = 0 ; i < store[3].size() ; i++ ){
		ll cur = store[ 3 ][i] ;
		ll rem = k - i ;
		if( rem < store[ 1 ].size() && rem < store[ 2 ].size() ){
			if( rem >= 0 )
				cur += store[ 1 ][ rem ] + store[ 2 ][ rem ] ;
			if( ans == -1 )
				ans = cur ;
			else if( ans > cur )
				ans = cur ;
		}
	}
	cout << ans << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	// cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
