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

vector<ll> to_check = { 0 , 4, 8, 15, 16, 23, 42 } ;

void check(){
	random_shuffle( to_check.begin() + 1 , to_check.end() ) ;
	vector<ll> num = {  4, 8, 15, 16, 23, 42 } ;
	ll a[10][10] ;

	function< ll(ll ,ll)> query = [  ] (ll i , ll j) -> ll {
		#ifdef CUST_DEBUG
			cout << "? " << i <<' ' << j << endl ;
			print( to_check[i] * to_check[j] );
			return to_check[i]*to_check[j] ;
		#endif
		cout << "? " << i <<' ' << j << endl ;
		ll x ;
		cin >> x ;
		return x ; 
	} ;

	for(ll i = 1 ; i <= 4 ; i++ ){
		a[i][i + 2] = query( i , i + 2 ) ;
	}

	ar<ar<pair<ll ,ll> , 10 > , 10 > b ;
	for(ll i = 1 ; i <= 4 ; i++ ){
		ll prod = a[ i ][i + 2] ;
		for( ll& x: num ){
			for( ll& y : num ){
				if( x != y && x * y == prod )
					b[ i ][i + 2] = { x , y } ;
			}
		}
	}
	auto show = [&](){
		for( ll i = 0; i < 10 ; i++ ){
			for(ll j = 0 ; j < 10 ; j++){
				if( b[i][j].F != 0 )
					print( i , j , b[i][j] );
			}
		}
	} ;
	show() ;
	vector<ll> ans( 7 ) ;
	if( b[1][3].F == b[3][5].F || b[1][3].F == b[3][5].S ){
		ans[ 3 ] = b[1][3].F ;
		ans[ 1 ] = b[1][3].S ;
		ans[ 5 ] = (b[3][5].F == ans[ 3 ]) ? b[3][5].S : b[3][5].F ;
	}
	else{
		ans[ 3 ] = b[1][3].S ;
		ans[ 1 ] = b[1][3].F ;
		ans[ 5 ] = (b[3][5].F == ans[ 3 ]) ? b[3][5].S : b[3][5].F ;
	}

	if( b[2][4].F == b[4][6].F || b[2][4].F == b[4][6].S ){
		ans[ 4 ] = b[2][4].F ;
		ans[ 2 ] = b[2][4].S ;
		ans[ 6 ] = (b[4][6].F == ans[ 4 ]) ? b[4][6].S : b[4][6].F ;
	}
	else{ 
		ans[ 4 ] = b[2][4].S ; 
		ans[ 2 ] = b[2][4].F ;
		ans[ 6 ] = (b[4][6].F == ans[ 4 ]) ? b[4][6].S : b[4][6].F ;
	}
	print( ans , '\n' , to_check ) ; 
	cout << "! " ;
	for( ll i = 1 ; i <= 6 ; i++ )
		cout << ans[ i ] << ' ' ;
	cout << endl ;
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
