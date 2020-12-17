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

#define int ll
const int INF = 1e18;
vector<vector<pair<int,int>>> adj( MAXN, vector<pair<int,int>>( 0 ) );
vector<int> d , p ;
int n ,m;

void dijkstra(int s) {
	d.assign(n + 1, INF);
	p.assign(n + 1, -1);
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
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}
}

vector<int> restore_path(int s, int t) {
	vector<int> path;
	path.reserve(MAXN);
	for (int v = t; v != s; v = p[v])
		path.push_back(v);
	path.push_back(s);

	reverse(path.begin(), path.end());
	// for(int i :path) cout << i<< '-';
	return path;
}

void check(){
	cin >> n >> m;
	for(ll i = 0 ; i < m ; i++){
		ll u ,v ,w ;
		cin >> u >> v >> w;
		u-- ,v-- ;
		adj[u].PB( {v ,w} );
		adj[v].PB( {u ,w} );
	}
	dijkstra(0);
	if(d[n-1] == INF){
		cout << -1 ;
		return; 
	}
	auto sp =  restore_path(0 ,n-1);
	for(auto& u : sp)
		cout << u + 1 <<' ';
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
