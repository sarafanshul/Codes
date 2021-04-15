#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define MP make_pair
using ll = long long ;
using db = long double ; // or double, if TL is tight
template< class T , size_t SZ> using ar = std::array<T , SZ> ; 
using namespace __gnu_pbds;
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
template< class T > using ordered_set =  tree<
	T, // Key type
	null_type, // Mapped-policy
	less<T>, // Key comparison functor
	rb_tree_tag, // Specifies which underlying data structure to use
	tree_order_statistics_node_update> ; // A policy for updating node invariants	
const long long MAXN = 2e5 +7;

ar<vector<ll> , MAXN> adj ;

void check(){
	ll n , k ;
	cin >> n >> k ;
	ordered_set<pair<ll ,ll>> st ;
	vector<ll> a( n ) ;
	for(ll i = 0 ; i < n ; i++)
		cin >> a[i] ;
	
	vector<ll> p(n) ; iota(ALL( p ) , 0) ;
	sort( ALL( p ) , [ & ] (ll x , ll y) {return a[x] < a[y] ;} ) ;

	while( k-- ){
		ll u , v ; cin >> u >> v ; u-- ,v-- ;
		adj[ u ].PB( v ) ; adj[ v ].PB( u ) ;
	}

	vector<ll> ans( n , 0 ) ;
	for(ll i = 0 ; i < n ; i++){
		ll idx = p[ i ] ;
		ll o_k = st.order_of_key( MP( a[idx] , 0 ) ) ;
		ll less = 0 ;
		for( ll &u : adj[ idx ] )
			less += a[ idx ] > a[ u ] ;
		ans[idx] = max( 0LL , o_k - less ) ;
		st.insert( { a[idx] , idx } ) ; 
	}
	for(ll i: ans)
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
