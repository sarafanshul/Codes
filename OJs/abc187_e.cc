#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
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

vector<ll> adj[MAXN] , D(MAXN , 0) , T1(MAXN , 0);
ll n ;
vector<pair<ll ,ll>> a(MAXN) ;

void dfs( ll v , ll p ){
	D[v] += T1[v] ;
	for(ll&u : adj[v]){
		if( u^p ) {
			T1[u] += T1[v] ;
			dfs( u , v );
		}
	}
}

void check(){
	cin >> n;
	for(ll i = 1 ; i <  n ; i++ ){
		cin >> a[i].F >> a[i].S ;
		adj[ a[i].F ].PB( a[i].S ) ;
		adj[ a[i].S ].PB( a[i].F ) ;
	}
	
	vector<ll> par( MAXN ) ;
	function<void(ll ,ll)> get_par = [&](ll v , ll p) {
		par[v] = p ;
		for(ll&u : adj[v])
			if( u^p ) get_par(u , v); 
	};
	get_par(1 , -1) ;

	ll q ;
	cin >> q;
	while(q--){
		ll t, e , x ;
		cin >> t >> e >> x ;
		ll fr = a[e].F , to = a[e].S ;
		if( t == 2 ) swap(to , fr) ;
		if( par[fr] == to )
			T1[fr] += x ;
		else 
			T1[1] += x  , T1[to] -= x;
	}
	dfs(1 , -1);
	for(ll i = 1 ; i <= n ; i++)
		cout << D[i] << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
