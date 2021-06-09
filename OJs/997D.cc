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
	ll n;
	cin >> n ;
	vector<ll> a( n ) ;
	map<ll ,ll> mp ;
	for(ll & i : a){
		cin >> i ;
		mp[i]++ ;
		assert( mp[i] <= 1 ) ;
	}

	vector<ll> res ;
	set<ll> vis ;
	function< bool( ll )> dfs = [&]( ll v ) -> bool {
		vis.insert( v ) ;
		res.PB( v ) ;
		if( res.size() == n ) return 1 ;
		bool ret = 0 ;
		if( v % 3 == 0 && vis.find( v / 3 ) == vis.end() && mp[ v / 3 ] != 0 ){
			ret |= dfs( v / 3 ) ;
		}
		if( vis.find( v * 2 ) == vis.end() && mp[ v * 2 ] != 0 )
			ret |= dfs( v * 2 ) ;

		if( !ret ){
			vis.erase( vis.find( v ) ) ;
			res.pop_back() ;
		}
		print( res ) ;
		return ret ;};

	for( ll i : a){
		res.clear() ;
		vis.clear() ;	
		print(i) ;
		if( dfs( i ) ){
			for(ll &x : res)
				cout << x << ' ' ;
			cout << '\n' ;
			return ;
		}
	}
	assert( false ) ;
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
