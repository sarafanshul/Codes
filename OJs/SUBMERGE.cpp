#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
 
bool solve() {
	ll n, m ;
	
	cin >> n >> m ;
	
	if( n + m == 0 )
		return 0 ;
	
	vector<ll> adj[n] ;
	
	for(ll i = 0 ; i < m ; i++){
		ll v, u ;
		cin >> u >> v ;
		u-- ; v-- ;
		adj[ v ].push_back( u ) ;
		adj[ u ].push_back( v ) ;
	}
	
	vector<ll> tin( n ), vis( n, 0 ), low( n ) ;
	ll timer = 0 ;
	map<ll, ll> cnt ;
	
	function<void(ll, ll)> dfs = [&](ll v, ll p) -> void { 
		vis[ v ] = 1 ;
		tin[ v ] = low[ v ] = timer++ ;
		
		ll child = 0 ;
		
		for(const ll& u : adj[v]){
			if( u == p )
				continue ;
			
			if( !vis[ u ] ){
				dfs( u, v ) ;
				low[ v ] = min( low[ u ], low[ v ] ) ;
				if( low[ u ] >= tin[ v ] && p != -1 ){
					cnt[ v ]++ ;
				}
				child++ ;
			}
			else{
				low[ v ] = min( tin[ u ], low[ v ] ) ;
			}
		}
		if( p == -1 && child > 1 )
			cnt[ v ]++ ;
	} ;  
	
	for(ll i = 0 ; i < n ; i++){
		if( ! vis[i] ){
			dfs( i, -1 ) ;
		}
	}
	
	ll ret = 0 ;
	for(const auto& [k, v] : cnt )
		ret += v > 0 ;
	
	cout << ret << '\n' ;
	
	return 1 ;
}
 
int main() {
	
	while( solve() ) ;
	
	return 0;
} 
