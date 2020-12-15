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
#define int long long
using namespace std;

const int N = 120021;

vector <int> vc[2];
vector <int> adj[N];
int mark[N];

int n ,m;

bool dfs(int v ,int color = 2){
	mark[v] = color;
	vc[color-1].PB(v);
	for(int u : adj[v]){
		if(!mark[u] && dfs(u ,3 - color)) return 1;
		if(mark[u] != 3 - color) return 1;
	}
	return 0;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int u ,v;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--;v--;
		adj[v].PB(u);
		adj[u].PB(v);
	}
	for(int i = 0; i < n; i++){
		if (!mark[i]){
			if(adj[i].empty()) continue;
			if(dfs(i)){
				cout << -1 << '\n';
				return 0;
			}
		}
	}
	for(int i = 0; i < 2 ;i++){
		cout << vc[i].size() <<'\n';
		for(int v :vc[i]) cout << v+1 <<' ';
		cout << '\n';
	}
	return 0;
}