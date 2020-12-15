#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
#define int long long
using namespace std;

inline bool sgn(int x){return (x>0)?1:0;}

const int MAXN = (1e5)*2 + 11;

int a[MAXN] ,sum_subTree[MAXN] ,mx_subTree[MAXN];;
vector<int> adj[MAXN];
int n ,ans = LONG_LONG_MIN;

void dfs1(int v ,int p){
	sum_subTree[v] = a[v];
	mx_subTree[v] = LONG_LONG_MIN;
	for(int u :adj[v]){
		if(u == p) continue;
		dfs1(u ,v);
		sum_subTree[v] += sum_subTree[u];
		mx_subTree[v] = max(mx_subTree[v] ,mx_subTree[u]);
	}
	mx_subTree[v] = max(mx_subTree[v] ,sum_subTree[v]);
}

void dfs2(int v ,int p ,int out){
	if(out != LONG_LONG_MIN) ans = max(ans ,sum_subTree[v] + out);

	vector<pair<int ,int>> minset;
	for(int u :adj[v]){
		if(u == p) continue;
		minset.PB(MP(mx_subTree[u] ,u));
		sort(minset.rbegin() ,minset.rend());
		if(minset.size() == 3) minset.pop_back();
	}
	minset.PB(MP(LONG_LONG_MIN ,-1));
	for(int u : adj[v]){
		if(u == p) continue;
		int cur = (minset[0].S == u) ? minset[1].F : minset[0].F;
		dfs2(u ,v ,max(out ,cur));
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int u ,v;
	cin >> n;
	for( int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i+1 < n ;i++){
		cin >> u >> v;
		u-- ; v--;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	dfs1(0 ,-1);
	dfs2(0 ,-1 ,LONG_LONG_MIN);
	cout << ((ans == LONG_LONG_MIN)? "Impossible" :to_string(ans)) ;
	return 0;
}