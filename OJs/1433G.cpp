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

const long long MAXN = 1e3 +7;

#define int ll 

const int INF = 1000000000;
vector<vector<pair<int,int>>> adj( MAXN, vector<pair<int,int>>(0) );
int n ,m;

void dijkstra(int s ,vector<ll>&d ) {
	d.assign(n, INF);
	d[s] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});

	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (pii edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
	}
}

vector<vector<int>> d(MAXN);

void check(){
	ll k;
	cin >> n >> m >> k ;

	
	for(ll i = 0 ; i < m ; i++){
		ll u ,v ,w ;
		cin >> u >> v >> w;
		u-- ,v-- ;
		adj[u].PB( {v ,w} );
		adj[v].PB( {u ,w} );
	}

	vector<pair<ll ,ll>> routes(k);
	for( auto &[u ,v] : routes){
		cin >> u >> v;
		u-- ,v-- ;
	}

	for(ll v = 0 ; v < n ; v++){
		dijkstra( v ,d[v] ) ;
	}
	ll ans = INF ;

	for(ll v = 0 ; v < n ; v++){
		for(auto &[to ,w] : adj[v]){
			ll cur = 0;
			for(auto &[a ,b] : routes){
				cur += min({ 
					d[a][b] ,d[a][v] + d[to][b] ,d[a][to] + d[v][b]
				 });
			}
			ans = min(ans ,cur) ;
		}
	}
	cout << ans << '\n';
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
