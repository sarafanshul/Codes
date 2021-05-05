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

ar<vector< pair< ll , ll > > , MAXN > adj ;
ll n , m , d ;

ar<ll , MAXN > dist , par ;

bool bfs(ll W){
	queue<ll> q ;
	q.push( 1 ) ;
	dist[1] = 0 ;
	while( !q.empty() ){
		ll v = q.front() ; q.pop() ;
		for( auto &[ u , w ] : adj[v] ) if( w <= W && dist[u] == -1 ){
			dist[ u ] = dist[ v ] + 1 ;
			q.push(u) ;
			par[ u ] = v ;
		}
	}
	return dist[ n ] != -1 && dist[ n ] <= d ;
}

void check(){
	cin >> n >> m >> d ;
	for(ll i = 0 ; i < m ; i++){
		ll u , v, wt ; cin >> u >> v >> wt ;
		adj[u].PB( { v , wt } ) ;
	}

	auto can = [&](ll mx) -> bool {
		dist.fill(-1) ;
		return bfs( mx ) ;
	};

	ll l = -1 , r = 1e10 , mid ;
	while( l + 1 < r ){
		mid = (l + r) / 2 ;
		if( can( mid ) )
			r = mid ;
		else 
			l = mid ;
	}

	if( !can( r ) ) cout << -1 ;
	else {
		cout << dist[n] << '\n' ;
		vector<ll> path ;
		for(ll u = n ; u != 1 ; u = par[u] ) path.PB( u ) ;
		path.PB( 1 ) ;
		reverse(ALL(path)) ;
		for( ll &i : path)
			cout << i << ' ' ;
	}

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
