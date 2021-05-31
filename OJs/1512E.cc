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

pair<bool , vector<ll>> find( ll n , ll sz , ll sm ){
	
	ll mx = 0 , mn = (sz*( sz + 1 )) / 2 ;
	
	for(ll i = 0 ; i < sz ; i++)
		mx += n - i ;
	
	if( sm < mn || sm > mx )
		return MP( 0 , vector<ll>() ) ;

	vector<ll> ret  ;
	ll cur = 0 ;
	for(ll i = n ; i >= 1 ; i-- ){
		ll sm_need = sm - cur ;
		ll elem_need = sz - ret.size() ;

		if( elem_need == 0 ) break ;

		if( sm_need >= i + ( (elem_need * (elem_need - 1)) / 2 ) ){
			ret.PB( i ) ;
			cur += i ;
		}
	}
	return MP( ret.size() == sz , ret ) ;

}

void check(){
	ll n , l , r , S;
	cin >> n >> l >> r >> S;

	auto x = find( n , r - l + 1 , S ) ;
	print( x ) ;
	if( x.F ){

		vector<bool> v(n + 1 , 0) ;
		for(ll i : x.S )
			v[i] = 1 ;

		vector<ll> ans ;
		for(ll i = 0 ; i < n ; i++)
			if( v[i + 1] == 0 )
				ans.PB( i + 1 ) ;

		for(ll i = 0 ; i < l - 1 ; i++)
			cout << ans[i] << ' ' ;

		for(ll i : x.S )
			cout << i << ' ' ;

		for(ll i = 0 ; i < n - r ; i++ ) 
			cout << ans[ n - ( r - l + 1 ) - i - 1 ] << ' ' ;

		cout << '\n' ;

	}else {
		cout << "-1\n" ;
 	}

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
