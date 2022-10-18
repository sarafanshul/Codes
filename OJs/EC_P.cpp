// https://www.spoj.com/problems/EC_P/
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
 
void solve() {
	ll n, m ;
	
	cin >> n >> m ;
	
	vector<ll> adj[n] ;
	
	for(ll i = 0 ; i < m ; i++){
		ll v, u ;
		cin >> u >> v ;
		u-- ; v-- ;
		adj[ v ].push_back( u ) ;
		adj[ u ].push_back( v ) ;
	}
	
	vector<pair<ll, ll>> ans ;
	vector<ll> tin( n ), vis( n ), low( n ) ;
	int timer = 0 ;
	
	function<void(ll, ll)> dfs = [&](ll v, ll p) -> void { 
		vis[ v ] = 1 ;
		tin[ v ] = low[ v ] = timer++ ;
		
		for(const ll& u : adj[v]){
			if( u == p )
				continue ;
			
			if( !vis[ u ] ){
				dfs( u, v ) ;
				low[ v ] = min( low[ u ], low[ v ] ) ;
				if( low[ u ] > tin[ v ] ){
					ans.push_back( { v, u } ) ;
				}
			}
			else{
				low[ v ] = min( tin[ u ], low[ v ] ) ;
			}
		}
	} ;  
	
	for(ll i = 0 ; i < n ; i++){
		if( ! vis[i] ){
			dfs( i, -1 ) ;
		}
	}
	
	if( ans.empty() )
		cout << "Sin bloqueos\n" ;
	else {
		cout << ans.size() << '\n' ;
		for( auto& [a, b] : ans ){
			if( a > b ) swap( a, b ) ;
		}
		sort( ans.begin(), ans.end() ) ;
		for( const auto& [a, b] : ans)
			cout << a + 1 << ' ' << b + 1 << '\n' ;
	}
}
 
int main() {
	
	ll t ;
	
	cin >> t ;
	
	for( ll i = 1 ; i <= t ; i++ ){
		cout << "Caso #" << i << '\n' ;
		solve() ;
	}
	
	return 0;
}
