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

ll solve( vector<ll> &box , vector<ll> &spec ){
	sort( ALL( box ) ) ;
	sort( ALL( spec ) ) ;

	ll n = box.size() , m = spec.size() ;
	vector<ll> onSpec(n + 1, 0) ;
	for(ll i = 0 ; i < n ; i++){
		ll p = lower_bound( ALL( spec ) ,  box[i] ) - spec.begin() ;
		if( p < m && spec[ p ] == box[ i ] )  onSpec[ i ] = 1 ;
	}
	for( ll i = n - 1 ; i >= 0 ; i-- ){
		onSpec[ i ] += onSpec[ i + 1 ] ;
	}
	ll ans = onSpec[ 0 ] ;
	for( ll i = 0 ; i < n ; i++ )
		box[i] -= i ;

	for( ll i = 0 ; i < m ; i++ ){
		// 0-th on position spec[i] => p-th on position spec[i] + p >= box[p]
		// spec[i] >= box[p] - p
		ll len = upper_bound( ALL(box) , spec[ i ] ) - box.begin() ;
		if( len <= 0 ) continue ;
		ll x = lower_bound( ALL( spec ) , spec[ i ] + len ) - spec.begin() - i + onSpec[ len ] ;
		ans = max( ans , x ) ; 
	}
	return ans ;
}

void check(){
	ll n , m ;
	cin >> n >> m; 
	vector<ll> posBox , negBox , posSpec , negSpec ;
	for(ll i = 0 ; i < n ; i++){
		ll x ; cin >> x ;
		if( x > 0 ) posBox.PB( x ) ;
		else negBox.PB( -x ) ;
	}
	for(ll i = 0 ; i < m ; i++){
		ll x ; cin >> x ;
		if( x > 0 ) posSpec.PB( x ) ;
		else negSpec.PB( -x ) ;
	} 

	cout << solve( posBox , posSpec ) + solve( negBox , negSpec ) <<'\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t_c = 1;	
	cin >> t_c;
	for(int i = 1 ; i <= t_c ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
