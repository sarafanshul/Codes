#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
#define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
using namespace std;

const size_t MAXN = 1e5 +7;

vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev) {
                    dfs(v, u);
                    sz[u] += sz[v];
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}
int leaf = -1;
void dfs1(vector<vector<int>> &adj ,int v ,int par){
	for(int u : adj[v]){
		if(u != par){
			if(adj[u].size() == 1){leaf = u;return;}
			dfs1(adj ,u ,v);
		}
	}
}

void check(){
	int n ,u ,v;
	cin >> n;
	vector<vector<int>> adj(n ,vector<int>(0));
	vector<int> par(n ,-1);
	int last;
	for(int i = 0; i < n-1;i++){
		cin >> v >> u;
		v-- ,u--;
		adj[v].PB(u);
		adj[u].PB(v);
		par[u] = v;
		par[v] = u;
		last = u;
	}
	vector<int> cnt = Centroid(adj);
	if(cnt.size() == 1){
		cout<< par[last]+1 << " " << last+1<<"\n";
		cout<< par[last]+1 << " " << last+1<<"\n";return;
	}
	// 2 cecntroids -> select one  ,remove leaf node from anathor ,add to first
	dfs1(adj ,cnt[0] ,cnt[1]);
// 	cout << leaf << "--\n";
	cout << par[leaf]+1<< " " << leaf+1 << "\n";
	cout << cnt[1]+1<< " " << leaf+1 << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t;	cin >> t;
	while(t--)check();
	return 0;
}
