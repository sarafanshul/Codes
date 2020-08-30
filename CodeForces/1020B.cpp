

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
int n;
vector<int> adj[2001];
bool visited[2001];

void dfs(int v){
	visited[v] = true;
	for (int u : adj[v]){
		if (visited[u]) {cout << u << " ";continue;};
		dfs(u);
	}
}



int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int v;
	for (int i = 1; i <= n; ++i){
		cin >> v;
		adj[i].PB(v); // directed
	}
	for (int i = 1 ; i <= n ; ++i){
		memset(visited ,false ,sizeof(visited));
		dfs(i);
	}
	
	return 0;
}