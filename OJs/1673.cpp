// Solution to finding the shortest (and longest) path on a Directed Acyclic Graph (DAG) using a topological sort in combination with dynamic programming
// for longest path 
// 1) reverse all the edge-distances (a =  a*(-1) ) 
// 2) find the shortest path
// 3) reverse the disatnces again (a = a*(-1) )
// https://www.youtube.com/watch?v=TXkDpqjDMHA&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P&index=16
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
#define MP make_pair

using namespace std;
const size_t MAXN = 1e5 +7;
const long long INF = 1e18;
vector<tuple<int ,int ,int>> e(MAXN ,tuple<int ,int  ,int>(0 ,0 ,0));

int n ,m;

void dfs(vector<vector<int>> &adj ,vector<bool> &vis ,int v){
	vis[v] = 1;
	for(int u : adj[v]) if(!vis[u]) dfs(adj ,vis ,u);
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int u ,v ,w;
	vector<vector<int>> adj(MAXN ,vector<int>(0)) ,re(MAXN ,vector<int>(0));
	vector<bool> vis1(MAXN) ,vis2(MAXN);
	cin >> n >> m;
	for(int i = 0; i < m ; i++){
		cin >> u >> v >> w;
		u--;v--;
		adj[u].PB(v);
		re[v].PB(u);
		e[i] = {u ,v ,-w};
	}
	dfs(adj ,vis1 ,0);
	dfs(re ,vis2 ,n-1);
	vector<int> dist(MAXN ,INF);
	dist[0] = 0;
	bool flag = 0;
	for(int i = 0; i < n ;i++){
		flag = 0;
		for(tuple<int ,int ,int> x :e){
			tie(u ,v ,w) = x;
			if(vis1[u] && vis2[v] && dist[u] + w < dist[v])
				flag = 1 ,dist[v] = dist[u] + w;
		}
	}
	if(flag) cout << "-1";
	else  cout << -dist[n-1];

	return 0;
}
