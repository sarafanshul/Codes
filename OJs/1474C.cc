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
#define arr array
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
	vector<ll> a(2*n) ;
	for(ll i = 0 ; i < 2*n ; i++){
		cin >> a[i] ; 
	}
	sort( ALL(a) ) ;

	function<vector<ll>(ll)> can = [&](ll x) -> vector<ll> {
		multiset<ll> mst ;
		for(ll & e : a)
			mst.insert(e) ;
		vector<ll> ans ;

		for(ll i = 0 ; i < n ; i++){
			auto it1 = mst.end() ;
			it1-- ;
			ll y = x - *it1 ;
			mst.erase( it1 ) ;
			auto is_in = mst.find( y ) ;
			if( is_in == mst.end() ) return { };

			ans.PB( x - y ) ;
			ans.PB( y ) ;
			x = max( x - y , y ) ;
			mst.erase( is_in ) ;
		}
		return ans ;
	} ;

	for(ll i = 0 ; i < 2 * n - 1 ; i++ ){
		ll x = a[i] + a[2* n - 1] ;
		auto ans = can( x ) ;
		if( ans.size() ){
			cout << "YES\n" << x <<'\n' ;
			for(ll j = 0 ; j < n ; j++){
				cout << ans[ 2*j ] << ' ' << ans[2 * j + 1] << '\n' ;
			}
			return ;
		}
	}
	cout << "NO\n" ;
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
