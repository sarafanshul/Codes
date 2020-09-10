// https://www.youtube.com/watch?v=MOy4UDjN8DM&list=PLZU0kmvryb_HZpDW2yfn-H-RxAu_ts6xq&index=10&t=1508s


// ==================== using DFS ========================
// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// #define INF INT_MAX
// // for overflow
#define int long long
#define INF LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 3*(1e5 +7);

vector<int> adj[MAXN];
int n ,m;
bool visited[MAXN];

int x;
void dfsUtil(int v ,int count ,int& maxCount){
	visited[v] = 1;
	count++;
	for(int u : adj[v]){
		if(!visited[u]){
			if(count >= maxCount){
				maxCount = count;
				x = u;
			}
			dfsUtil(u ,count ,maxCount);
		}
	}
}

void dfs(int v ,int& maxCount){
	memset(visited ,0 ,sizeof(visited));
	int count = 0;
	dfsUtil(v ,count + 1 ,maxCount);
}
 
int diameter(int v){
    if(n == 1) return 0;
	int maxCount= INT_MIN;
	dfs(v ,maxCount);
	dfs(x ,maxCount);
	// returning no of nodes , e = n-1
	return maxCount-1;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
// 	cin.exceptions(cin.failbit);
	int q ,u ,v;
	cin >> n;
	int start;
	for(int i = 0 ;i < n-1 ; i++){ // 0 based indexing
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
		start = u;
	}
	cout << diameter(start)*3 << "\n";

	return 0;
}
