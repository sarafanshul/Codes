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
	ll n; 
	cin >> n ;
	vector<ll> a( n ) ;
	for( ll i = 0 ; i < n ; i++ ){
		cin >> a[ i ] ;
	}

	if( n == 1 ) {
		cout <<'0' <<'\n' ;
		return ;
	}
	map<ll ,ll> cnt ;

	function< void(ll ,ll)> go = [&](ll x , ll y){
		map<ll ,ll> tmp ;
		for(ll i = x - 1 ; i <= x + 1; i++){
			for(ll j = y - 1 ; j <= y + 1 ; j++)
				tmp[ i - j ]++ ;
		}
		for( auto &[k ,v] : tmp )
			cnt[ k ]++ ;
	} ;

	for(ll i = 1 ; i < n ; i++){
		go( a[i - 1] , a[i] ) ;
	}

	ll mx = 0 ;
	vector<ll>Ds ;
	for( auto &[k , v] : cnt ){
		if( v > mx )
			mx = v , Ds.clear() ;
		if( v == mx ) Ds.PB( k ) ;
	}
	
	function< bool( vector<ll>& ,ll)> solve = [ ]( vector<ll>& b  ,ll d) -> bool{
		for( ll i = 1 ; i < b.size() ; i++ ){
			ll a2 = b[i - 1] - d ;
			if( abs(a2 - b[i]) > 1 ) return 0;
			b[i] = a2 ;
		}
		return 1 ;
	} ;
	
	ll ret = 1e17 ;
	for( ll D : Ds){
		for(ll i = -1 ; i <= 1 ; i++){
			vector<ll> b = a ;
			b[0] += i ;
			if( solve( b , D ) ){
				ll tmp = 0 ;
				for( ll j = 0 ; j < n ; j++ )
					tmp += abs( a[j] - b[j] ) ;
				ret = min( tmp , ret ) ;
				print(b , tmp) ;
			}
		}
	}
	cout << (ret == 1e17 ? -1 : ret) << '\n' ;
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
