

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
using namespace std;

const int MAXN = 1e5+7;
const int MAXC = 1e5+7;

vector<int> adj[MAXN] ,color[MAXC];
bool visited[MAXN];
int shade[MAXC];

int n ,m;

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int c ,u ,v;
	cin >> n >> m;
	for(int i = 1; i <= n ; i++){
		cin >>c ;
		shade[i] = c;
		color[c].PB(i);
	}
	for(int i = 0; i < m ;i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	int maxi = -1 ,ans = -1;

	for(int i = 1; i <= 100000; i++){
		if(! color[i].size()) continue;
		int cnt = 0; 
		set<int> st;
		for(int v : color[i]){
			for( int u : adj[v]){
				if(shade[u] != shade[v]) st.insert(shade[u]);
			}
		}
		cnt = st.size();
		if(cnt > maxi){ans = i; maxi = cnt;}
	} 
	cout << ans;
	return 0;
}