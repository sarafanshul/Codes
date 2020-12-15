
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;

inline bool sgn(int x){return (x>0)?1:0;}

const int MAXn = 100011;
vector<int> adj[MAXn];
int n ,curr_color ,color[MAXn];
bool ok;

void dfs(int v ,int p){
	ok = ok && (color[v] == curr_color);
	for(int u :adj[v]){
		if(u != p) dfs(u ,v);
	}
}

bool solve(int v){
	int ans = 1;
	for(int u : adj[v]){
		curr_color = color[u];
		ok = 1;
		dfs(u ,v);
		ans = ans && ok;
	}
	return ans;
}


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	int u ,v;
	for(int i = 0; i < n-1 ;i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	for(int i = 0; i < n; i++) cin >> color[i+1];

	int root1 = -1, root2 = -1;
	for(int i = 1; i <= n; i++){
		for(int elem : adj[i]){
			if(color[elem] != color[i]){
				root1 = elem;
				root2 = i;
			}
		}
	}
	if(root1 == -1) {
		cout << "YES\n1";return 0;
	}
	bool res1 = solve(root1);
	bool res2 = solve(root2);
	if (res1) cout << "YES\n" << root1;
	else if (res2) cout << "YES\n" << root2;
	else cout << "NO\n";
	return 0;
}