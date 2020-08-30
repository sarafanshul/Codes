

	#pragma GCC optimize("O3")
	#pragma comment(linker, "/stack:200000000")
	#pragma GCC optimize("unroll-loops")

	#include <bits/stdc++.h>

	#define ALL(x) x.begin(),x.end()
	#define PB push_back
	#define EB emplace_back
	#define F first
	#define S second
	#define ll long long

	using namespace std;
	int n ,m;
	vector<int> adj[200001];
	bool visited[200001];
	int deg[200001];
	vector<int> comp;

	void dfs(int v){
		visited[v] = true;
		comp.PB(v);
		for (int u : adj[v]){
			if (!visited[u])
				dfs(u);
		}
	}



	int32_t main(){
		ios_base::sync_with_stdio(false); cin.tie(NULL);
		memset(visited ,false ,sizeof(visited));
		cin >> n >> m;
		int v ,u;
		for (int i = 0; i < m; ++i){
			cin >> v >> u;
			--v;--u;
			adj[v].PB(u);
			adj[u].PB(v);
			++deg[u];++deg[v];
		}
		int count = 0;
		for (int i = 0 ; i < n ; ++i){
			if (visited[i]) continue;
			comp.clear();
			dfs(i);
			bool ok = true;
			for(int v :comp) ok &= (deg[v] == 2);
			if (ok) count++;
		}
		cout << count;
		
		return 0;
	}