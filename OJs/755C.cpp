#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
bool used[100005];

void dfs(int v){
	used[v] = true;
	for(int u : g[v]){
		if (used[u]) continue;
		dfs(u);
	}
}

int main(){
	int n ,m ,tc ,num ,t = 1 ,u;
	cin >> n;
	for (int i = 0; i < n ; ++i){
		cin >> u;
		u--;
		g[u].push_back(i);
		g[i].push_back(u);
	}
	long long ans = 0;
	for (int i = 0; i < n ; ++i){
		if (used[i]) continue;

		ans++;
		dfs(i);
	}
	cout << ans;
}