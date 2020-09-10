// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;
int n ,da ,db;

int timer ,dist[MAXN] ,l;
vector<int> tin, tout ,h;
vector<vector<int>> up ,adj;

void dfs(int v, int p){
	tin[v] = ++timer;
	up[v][0] = p;
	h[v] = h[p]+1;
	for (int i = 1; i <= l; ++i)up[v][i] = up[up[v][i-1]][i-1];
	for (int u : adj[v]) {if (u != p) dfs(u, v);}
	tout[v] = ++timer;
}

bool is_ancestor(int u, int v){return tin[u] <= tin[v] && tout[u] >= tout[v];}

int lca(int u, int v){
	if (is_ancestor(u, v))return u;
	if (is_ancestor(v, u))return v;
	for (int i = l; i >= 0; --i) {if (!is_ancestor(up[u][i], v))u = up[u][i];}
	return up[u][0];
}

void preprocess(int root) {
	tin.resize(n);tout.resize(n);h.resize(n);h[root] = 0;
	timer = 0;l = ceil(log2(n));
	up.assign(n, vector<int>(l + 1));
	dfs(root, root);
}

int dt(int u ,int v){
	int _lca = lca(u ,v);
	return (h[u] - h[_lca]) + (h[v] - h[_lca]);
}

void bfs(int v) {
	memset(dist ,-1 ,sizeof(dist));dist[v] = 0;
	queue<int> q;
	q.push(v);
	int u;
	while(!q.empty()){
		v = q.front();q.pop();
		for(int u :adj[v]){if(dist[u] == -1){dist[u] = dist[v] + 1;q.push(u);}}
	}
} 

pair<int ,int> farthest(){
	int _max = -1 ,node = -1;
	for(int i = 0 ;i <= n ;i++) if(dist[i] > _max) {_max = dist[i];node = i;}
	return MP(node ,_max);
}

int diam(int u){
	bfs(0);
	pair<int ,int> last = farthest();
	bfs(last.F);
	return farthest().S;
}

void check(){
	int a ,b ,u ,v;
	cin >> n >> a >> b >> da >> db;a--;b--;
	adj.assign(n+1 ,vector<int>(0));

	for(int i = 0 ;i < n-1; i++) {
		cin >> u >> v;u--;v--;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	preprocess(0);
	// case 1)
	if(dt(a ,b) <= da){cout << "Alice\n";return;}
	// case 2)
	if((2*da) >= diam(0)){cout << "Alice\n";return;}
	// case 3)
	if(db > (2*da)){cout << "Bob\n";return;}
	// case 4)
	cout << "Alice\n";return;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){check();}
	return 0;
}
