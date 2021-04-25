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

ar<ll ,2> intersect( const ar<ll ,2> &a , const ar<ll ,2> &b ){
	return { max( a[0] , b[0] ) , min( a[1] , b[1] ) } ;
}

void check(){
	ll n , k ;
	cin >> n >> k ;
	vector<ll> h(n) ;
	for(ll &i : h) 
		cin >> i ;

	ar<ll ,2> range = { h[0] , h[0] + 1 } ;

	for(ll i = 1 ; i < n ; i++){
		range[ 0 ] -= k - 1 ;
		range[ 1 ] += k - 1 ;
		ar<ll ,2> new_range = { h[i] , h[i] + k } ;
		range = intersect( range , new_range ) ;

		if( range[ 0 ] >= range[ 1 ] )
			break ;
	}
	cout << ( range[ 0 ] <= h.back() && h.back() < range[1] ? "YES" : "NO" ) << '\n' ;
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
