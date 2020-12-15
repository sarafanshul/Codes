

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

const int MAXN = 3*(1e4) + 7;

using namespace std;

vector<int> adj[MAXN];
bool visitsd[MAXN] = {false};
bool ok = 0;


void dfs(int v ,int d){
	if (v == d){
		ok = 1;return;
	}
	visitsd[v] = 1;
	for(int u : adj[v]){
		if (!visitsd[u])
			dfs(u ,d);
	}
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,d ,v;
	cin >> n >> d;
	for (int i = 1;  i <= n; i++){
		cin >> v;
		adj[i].PB(v+i);
	}
	dfs(1,d);
	cout << (ok)?"YES":"NO";
	return 0;
}