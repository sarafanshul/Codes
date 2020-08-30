

#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long;

using namespace std;

const int MAXN = 200001;
vector<int> adj[MAXN]; // graph represented as an adjacency list

vector<bool> visited(MAXN);
// vector<bool> codn(MAXN);
int D[MAXN];

int dfs(int v) {
    visited[v] = true;
    int cnt = 0;
    for (int u : adj[v]) {
        if (visited[u]) continue;
        cnt += dfs(u); // no of nodes
    }
    if (!cnt){
		D[cnt+1]++;
		return cnt+1;    	
    }
    D[cnt]++;
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n ,u ,v ,c;

	cin >> n;
	
	for (int i = 2 ; i <= n ; ++i){
		cin >> v;
		adj[v].PB(i);
		adj[i].PB(v);
	}
	dfs(1);
	int j = 1;
	vector<int> ans(n+1);
	for(int i = 1; i <=n ; ++i){
		while(D[i]--){ ans[j] = i ;j++;}
	}
	for(int i = 1; i <= n; ++i){
		cout << ans[i] <<" ";
	}

	return 0;
}