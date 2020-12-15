

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

const int MAXN = 3*(1e5) + 7;

using namespace std;

vector<int> adj[MAXN];
int visitsd[MAXN];
bool ok = 0;
vector<int> c(MAXN);
int cost = 0;


void dfs(int v){
	visitsd[v] = cost[v];
	for(int u : adj[v]){
		if (!visitsd[u])
			dfs(u);
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,m ,v ,u;
	cin >> n >> m;
	memset(visitsd ,LONG_LONG_MAX ,sizeof(visitsd));
	for(int i = 1; i <= n ; ++i) cin >> c[i];
	for(int i = 0; i < m ; i++){
		cin >> v >> u;
		adj[v].PB(u);
		adj[u].PB(v);
	}
	for(int i = 1; i <= n; i++){
		if (visitsd[i] == LONG_LONG_MAX){
			cost += c[i];
			dfs(i);
		}else {
			if(visitsd[i] > c[i]){
				cost -= visitsd[i];
				cost += c[i];
			}
		}
	}
	cout << cost;
	return 0;
}