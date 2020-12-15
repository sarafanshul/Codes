// https://codeforces.com/contest/456/problem/E (TLE)
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
// // for overflow
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 3*(1e5 +7);
vector<int> adj[MAXN];
int group[MAXN],_gp = 1 ,group_d[MAXN] ,n ,m ,x;
bool visited[MAXN];

void dfsUtil(int v ,int count ,int& maxCount){
	visited[v] = 1;count++;
	for(int u : adj[v]){if(!visited[u]){
		    if(count >= maxCount){maxCount = count;x = u;}
			dfsUtil(u ,count ,maxCount);
		}
	}
}

void dfs(int v ,int& maxCount){
	memset(visited ,0 ,sizeof(visited));
	int count = 0;
	dfsUtil(v ,count + 1 ,maxCount);
}

inline int diameter(int v){
	int maxCount= INT_MIN;
	dfs(v ,maxCount);dfs(x ,maxCount);
	return maxCount;
}

void calc(int v){
	if(group[v] == -1) {group[v] = _gp++;group_d[group[v]] = 0;return ;} // single element 
	int dia = diameter(v)-1;
	group_d[group[v]] = dia; // update
}

inline int val(int x ,int y){return((((int)ceil((float)group_d[group[x]]/2) + (int)ceil((float)group_d[group[y]]/2))) + 1);}

void check(){
	int m ,q ,u ,v ,a ,x ,y ,dt;;
	cin >> n >> m >> q;
	for(int i = 0; i < m ;i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
		if(group[u] == -1 && group[v] == -1){group[u] = group[v] = _gp++;}
		else if(group[u] == -1) group[u] = group[v];
		else group[v] = group[u];
	}
	for(int i = 1 ;i <= n ;i++){
	    if(group[i] == -1) {calc(i);}
		else if(group_d[group[i]] == -1) {calc(i);}
	}
	while(q--){
		cin >> a >> x;
		if(a == 1) cout << group_d[group[x]] << "\n";
		else {
		    cin >> y;
			if(group[x] == group[y]) continue;
			dt = max({group_d[group[x]] ,group_d[group[y]] ,val(x ,y)});
            int temp = group[y];
			for(int i = 0 ;i <= n ;i++)if(group[i] == temp)group[i] = group[x]; // update
			group_d[group[x]] = dt;
 		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
    memset(group ,-1 ,sizeof(group));memset(group_d ,-1 ,sizeof(group_d));
	int t = 1;
	while(t--)check();
	return 0;
}
