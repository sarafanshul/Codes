#include <bits/stdc++.h>
using namespace std;

#define int long long
 
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
 
int n, k, sz, ans = 0;
bool vis[N];
vector<int> g[N];

template<typename T>  
T pow(T a, T b, T m){
	int ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

void dfs(int u) {
	if(vis[u])
		return;
	sz++;
	vis[u] = true;
	for(auto &it:g[u])
		dfs(it);
}
 
int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	int ans = pow<int>(n, k, MOD);
	for(int i=1;i<=n-1;i++) {
		int u, v, x;
		cin>>u>>v>>x;
		if(x == 0)
			g[u].push_back(v), g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) {
		if(vis[i])
			continue;
		sz = 0;
		dfs(i);
		ans -= pow<int>(sz, k, MOD);
		ans += MOD;
		ans %= MOD;
	}
	cout<<ans<< "\n";
	return 0;
}