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
const long long MAXN = 2e5 +7;

void check(){
	ll n  ;
	cin >> n ;
	vector<ll> b( n + 2 ) ;
	ll sm = 0 ;

	for(ll &i : b ){
		cin >> i ;
		sm += i ;
	}

	sort( ALL( b ) ) ;

	function < pair<bool , ll>(ll) > can = [&]( ll idx ) -> pair<bool , ll>{

		ll X = sm - b[idx] ;
		for(ll i = 0 ; i < n + 2 ; i++){
			if( i == idx ) continue ;
			if( X - b[i] == b[idx] ){
				return MP( 1 , i ) ;
			}
		}
		return MP( 0 , -1 ) ;

	} ;
	auto xx = can( n ) ;
	if( xx.F ){
		for(ll i = 0 ; i < n + 2 ; i++ )
			if( i != n && i != xx.S )
				cout << b[i] << ' ' ;
		cout << '\n' ;
		return ;
	}

	xx = can( n + 1 ) ;
	if( xx.F ){
		for(ll i = 0 ; i < n + 2 ; i++ )
			if( i != n + 1 && i != xx.S )
				cout << b[i] << ' ' ;
		cout << '\n' ;
		return ;
	}
	cout << "-1\n" ;
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
