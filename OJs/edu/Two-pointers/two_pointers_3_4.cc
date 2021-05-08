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
using ld = long double ; // or double, if TL is tight
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
const long long MAXN = 1e6 +7;

ll a[4][MAXN] ;
ll n[4] ;

void check(){
	

	for(ll i = 0 ; i < 4 ; i++){
		cin >> n[i] ;

		for(ll j = 0 ; j < n[i] ; j++ )
			cin >> a[i][j] ;
		sort( a[i] , a[i] + n[i] ) ;
	}

	ll idx[4] { } ;
	ll ans[4] ;
	ll df = 1e18 ;

	while( idx[0] < n[0] && idx[1] < n[1] && idx[2] < n[2] && idx[3] < n[3] ){
		ll mx = 0 , mn = 1e18 ;
		for( ll i = 0 ; i < 4 ; i++ ){
			mx = max( mx , a[i][ idx[i] ] ) ;
			mn = min( mn , a[i][ idx[i] ] ) ;
		}
		if( mx - mn < df ){
			df = mx - mn ;
			for( ll i = 0 ; i < 4 ; i++ ){
				ans[i] = a[i][ idx[i] ] ;
			}
		}
		for( ll i = 0 ; i < 4 ; i++ ){
			if( a[i][ idx[i] ] == mn )
				idx[i]++ ;
		}
	}

	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n' ;

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
