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
#define ll long long
#define double long double
#define MP make_pair

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

const long long MAXN = 2e5 +7;

vector<ll> adj[MAXN] , C(MAXN) , H(MAXN) ;
ll n , m;

bool vis[MAXN] = {0} ;
void dfs(ll v , ll p){
	vis[v] = 1 ;
	for(ll &u : adj[v]){
		if( vis[u] ) H[v] = max( { H[v] , H[u] , C[u] } ) ;
		else if( u ^ p ){
			dfs( u , v) ;
			H[v] = max( { H[v] , H[u] , C[u] } );
		}
	}
}

void check(){
	cin >> n >> m ;
	for(ll i = 1 ; i <= n ; i++){
		cin >> C[i] ;
		H[i] = -1e18 ;
	}

	for(ll i = 0 ; i < m ; i++){
		ll u , v ;
		cin >> u >> v;
		adj[u].PB( v ) ;
	}
	for(ll i = 1 ; i <= n ; i++)
		if(!vis[i])
			dfs( i , -1 ) ;

	ll ans = -1e18 ;
	for(ll i = 1 ; i <= n ; i++){
		if(adj[i].size() )
			ans = max( ans , H[i] - C[i] ) ; 
	}
	cout << ans << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
