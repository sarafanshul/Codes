#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long

using namespace std;

const int MOD = 1e9+7;
const int MAXN = 3e6+7;

vector<int> adj[MAXN];
bool visited[MAXN] = {0};
int n ,m;


int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	int u ,v;
	for(int i = 0; i < m;++i){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	queue<int> q;
	q.push(1);
	vector<int> p(n+1);
	p[1] = -1;

	while(!q.empty()){
		u = q.front();q.pop();
		if(u == n) break;
		for(int v :adj[u]){
			if(!p[v]){
				p[v] = u;
				q.push(v);
			}
		}
	}

	if(!p[n]) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> ret;
	u = n;
	while(u > 0){
		ret.PB(u);
		u = p[u];
	}
	cout << ret.size() << "\n";
	for(int i = ret.size()-1; i>=0; --i){
		cout << ret[i] << " ";
	}
	return 0;
}
