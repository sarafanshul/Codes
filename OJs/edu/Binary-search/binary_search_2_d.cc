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

	ll m , n ;
	cin >> m >> n ;
	vector<ll> t(n) , z(n) , y(n) ;

	for(ll i = 0 ; i < n ; i++){
		cin >> t[i] >> z[i] >> y[i] ;
	}

	// bs for time ;

	auto can = [&](ll tm) -> bool {
		ll cnt = 0 ;
		for(ll i = 0 ; i < n ; i++){
			ll cur = ( tm / (t[i] * z[i] + y[i] ) ) * z[i] ;
			ll mod = tm % ( t[i] * z[i] + y[i] ) ;
			mod = min( mod , t[i]*z[i] ) ;
			cur += mod / t[i] ;
			cnt += cur ;
		}
		return cnt >= m ;
	};

	ll l = -1 , r = 1e12 , mid ;
	while( l + 1 < r ){
		mid = (l + r) / 2 ;
		if( can( mid ) )
			r = mid ;
		else l = mid ;
	}

	auto find = [&](ll tm) -> vector<ll> {
		vector<ll> ans(n , 0) ;
		for(ll i = 0 ; i < n ; i++){
			ll cur = ( tm / (t[i] * z[i] + y[i] ) ) * z[i] ;
			ll mod = tm % ( t[i] * z[i] + y[i] ) ;
			mod = min( mod , t[i]*z[i] ) ;
			cur += mod / t[i] ;
			ans[ i ] = min( m , cur ) ;
			m -= ans[ i ] ;
			assert( ans[i] >= 0 ) ;
		}
		return ans ;
	};

	auto ans = find( r ) ;


	cout << r << '\n' ;
	for(ll & i : ans)
		cout << i << ' ' ;

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
