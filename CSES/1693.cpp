// https://cses.fi/problemset/task/1693 Euler Tour;
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
#define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;
vector<int> adj[MAXN] ,in(MAXN) ,out(MAXN) ,path;
bool has_path;
int n ,m;

void dfs(int v){
	while(out[v] != 0) dfs(adj[v][--out[v]]);
	path.PB(v);
}

bool check(){
	int s = 0 ,e = 0;
	for(int i = 0; i <= n ; i++){
		if((out[i] - in[i] > 1) || (in[i] - out[i] > 1)) return 0;
		else if(out[i] - in[i] == 1)s++;
		else if(in[i] - out[i] == 1)e++;
	}
	return ((e == 0 && s == 0)||(s == 1 && e <= 1));
}

inline bool check_path(){
	// for checking connected components;
	return ((int)path.size() == m + 1) && (path[0] == n); // idk why 0 == n;
}

void euler_tour(int start = 1){
	has_path = check();
	dfs(start);
	has_path = check_path();
	if(has_path){
		reverse(ALL(path));
		for(size_t i = 0; i < path.size() ;i++){cout << path[i] << " ";}
	}else  cout << "IMPOSSIBLE";
}

void calc(){
	int u ,v;
	path.reserve(2*MAXN);
	cin >>n >> m;
	for(int i = 0 ; i < m ;i++){
		cin >> u >> v;
		adj[u].PB(v);
		in[v]++;
		out[u]++;
	}
	euler_tour();
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){calc();}
	return 0;
}
