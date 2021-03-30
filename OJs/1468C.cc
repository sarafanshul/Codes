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
using namespace std;
template< class T , size_t SZ> using ar = array<T , SZ> ; 
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
	ll q ;
	cin >> q ;
	set<ll> two ;
	set<pair<ll ,ll> , greater<pair<ll ,ll>>> three ;
	map<ll ,ll> money ;
	ll i = 1 ;
	vector<ll> ans ;
	for(ll ii = 1 ; ii <= q ; ii++) {
		ll t ; cin >> t ;
		if( t == 1 ){
			ll x ; cin >> x ;
			two.insert( ++i ) ;
			three.insert( { x ,-i } ) ;
			money[ i ] = x ;
		}else if( t == 2 ){
			auto it = two.begin() ;
			three.erase( { money[ *it ] , -( *it ) } ) ;
			ans.PB( *it ) ;
			two.erase( it ) ;
		}else {
			auto it = three.begin() ;
			two.erase( -(*it).S ) ;
			ans.PB( -(*it).S ) ;
			three.erase( it ) ;
		}
	}
	for(auto &x :ans) cout << x << ' ' ;
	cout << '\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
