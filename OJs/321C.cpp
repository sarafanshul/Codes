#include <bits/stdc++.h>
using namespace std;
// typedef long double ld;
// const int maxn = 2e5 + 17, maxv = 1e6 + 17, mod = 1e9 + 7;
 const long long A=100000000000000LL,N=228228;
int n ,m;
vector<int> g[N];
long long c[N] ,_ret;

void dfs(int v = 0, int pr = -1 ,int k = c[0]){
	if (k > m) return;
	int ok = 1;
	for(int i : g[v]){
		if (i != pr) {
			ok = 0;
			dfs(i ,v ,k*c[i] + c[i]);
		}
	}
	_ret += ok;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	for(int  i = 0 ;i < n; ++i) cin >> c[i];
	for(int v, u, i = 1; i < n; i++){
		cin >> v >> u, v--, u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs();
	cout << _ret << '\n';
	return 0;
}

