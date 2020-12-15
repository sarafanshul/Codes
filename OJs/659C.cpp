#include <bits/stdc++.h>
using namespace std;

const int Alp = 20;

void check(){
	int n;
	string a, b;
	cin >> n >> a >> b;

	bool bad = false;
	vector<vector<int>> adj(Alp);
	for (int i = 0; i < n; ++i)
		if (a[i] != b[i]){
			if (a[i] > b[i]){
				bad = true;
				cout << "-1\n";
				return;
			}
			adj[a[i]-'a'].push_back(b[i]-'a');
			adj[b[i]-'a'].push_back(a[i]-'a');
		}

	vector<bool> mark(Alp);
	function<void(int)> dfs = [&](int u){
		mark[u] = true;
		for (auto v : adj[u])
			if (!mark[v])
				dfs(v);
	};

	int ans = Alp;
	for (int i = 0; i < Alp; ++i)
		if (!mark[i])
			dfs(i), --ans;
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		check();
	}
	return 0;
}
