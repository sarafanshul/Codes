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

const long long MAXN = 1e5 +7;

const ll INF = 1e18;
vector<pair<ll ,ll >> adj[MAXN] ;
vector<ll> d , p , h[MAXN];
ll n ,m ,k;
bool mark[MAXN] = {0};
ll ans = 0;

void dijkstra(ll s) {
	d[s] = 0;
	using pii = pair<ll, ll>;
	set<pii> st;
	for(ll i = 0 ; i < n; i++) st.insert( {d[i] , i} );

	while( !st.empty()) {
		ll v = st.begin()->second ;
		st.erase(st.begin());

		for( auto &[u ,w] : adj[v]){
			if(d[v] + w < d[u] || (d[v] + w == d[u] && mark[u]) ){
				st.erase( {d[u] , u} );
				d[u] = d[v] + w;
				if(mark[u]) mark[u] = 0  ,ans--;
				st.insert({ d[u] ,u });
			}
		}
	}
}


void check(){
	cin >> n >> m >> k;
	for(ll i = 0 ; i < m ; i++){
		ll u , v, w;
		cin >> u >> v >> w ;
		u-- ,v-- ;
		adj[u].PB( {v , w} );
		adj[v].PB( {u , w} ); 
	}

	d.assign(n + 1, INF);
	
	for(ll i = 0 ; i < k ; i++){
		ll v ,w ;
		cin >> v >> w;
		v -- ;
		h[v].PB(w);
		d[v] = min(d[v] ,w);
		if( !mark[v] ) mark[v] = 1 ,ans++;
	}

	dijkstra(0) ;

	cout << k - ans <<'\n';
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
