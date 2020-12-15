// diameter of a tree using BFS


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
// #define int long long
#define MP make_pair
#define INF INT_MAX

using namespace std;
const uint64_t MAXN = 3*(1e5 + 7);

vector<long long> adj[MAXN];
long long dist[MAXN];
bool visited[MAXN];
int n ,m;

void bfs(long long v) {
	memset(dist ,-1 ,sizeof(dist));
	dist[v] = 0;
	queue<long long> q;
	q.push(v);
	long long u;
	while(!q.empty()){
		v = q.front();q.pop();
		for(long long u :adj[v]){
			if(dist[u] == -1){
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
} 

pair<long long ,long long> farthest(){
	long long _max = -1 ,node = -1;
	for(int i = 0 ;i < n ;i++) 
		if(dist[i] > _max) {_max = dist[i];node = i;}
	return MP(node ,_max);
}

void check(){
	int q ,u ,v;
	cin >> n;
	if(n == 1){cout<<"1\n";return;}
	for(int i = 0 ;i < n ; i++){ 
		cin >> u >> v; u--;v--;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	bfs(0);
	pair<long long ,long long> last = farthest();
	bfs(last.F);
	last = farthest();
	long long max_d = last.S;
	bool md[n+1] = {0};
	for(int i = 0 ;i < n; i++)if(dist[i] == max_d)md[i] = 1;
	bfs(last.F);
	last = farthest();
	max_d = last.S;
	for(int i = 0 ;i < n; i++)if(dist[i] == max_d)md[i] = 1;
	for(int i = 0 ; i < n; i++) cout << max_d + md[i] <<"\n";
	
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	check();
	return 0;
}
