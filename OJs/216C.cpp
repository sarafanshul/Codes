#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
 
using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN]; // graph represented as an adjacency list
int n; // number of vertices

vector<bool> visited(MAXN);
vector<bool> codn(MAXN);
int D[MAXN];

void dfs(int v) {
    visited[v] = true;
    D[v] = codn[v];
    for (int u : adj[v]) {
        if (visited[u]) continue;
        dfs(u);
        D[v] += D[u];
    }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n ,u ,v ,c;

	cin >> n;
	for ( int i = 0 ; i < n-1 ; ++i) {
		cin >> v >> u >> c;
		v--;u--;
		adj[v].PB(u);
		adj[u].PB(v);
		codn[v] = (c == 2) ? true : false;
		codn[u] = (c == 2) ? true : false;
	}

	dfs(0);
	vector<int> ans;
	for (int i = 0; i < n ; ++i){
		if (codn[i] && D[i] == 1) ans.PB(i + 1);
	}
	cout << ans.size() <<"\n";
	for(int i : ans) cout << i << " ";

	return 0;
}