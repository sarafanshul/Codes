
// heirholzera impl for 508D

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
// #define INT_MAX LONG_LONG_MAX
// #define INT_MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 4000; // ("zz " - "00" = 2368)
const int diff = 1500;
vector<vector<int>> adj(MAXN ,vector<int>(0));
bool visited[MAXN] = {0} ,has_path = false;
int indeg[MAXN] = {0} ,outdeg[MAXN] = {0} ,n ,m ,start_node = -1 ,end_node;;
vector<int> path;
vector<string> _map(MAXN);

template<typename T = int>
T pow(T x ,T y) {  
    if(x == 0 && y == 0 )return 1;
    int res = 1;
    if (x == 0) return 0;
    while (y > 0) {if (y & 1) res = res*x;y = y>>1;x = x*x;}
    return res;  
}

inline int construct(string s){
	int res = 0;
	for(size_t i = 0; i < s.size() ;++i){res += s[i]*pow<int>(31 ,i);}
	_map[res - diff] = s;
	return res - diff;
}

void retrive_path(){
    cout << "YES\n";
	string p;
	for(size_t i = 0; i < path.size(); i++){
	    if(i != 0 ) p += _map[path[i]][1];
		else p += _map[path[i]];
	}
	cout<< p;
}

bool check(){
	// for checking indeg/outdeg conditions
	int start_nodes =0 , end_nodes = 0;
	for(int i= 0 ;i < MAXN ;i++){
		
		if((outdeg[i] - indeg[i] > 1) || (indeg[i] - outdeg[i] > 1))
			return false;	
		else if (outdeg[i] - indeg[i] == 1){
			start_nodes++;
			start_node = i;}
		else if (indeg[i] - outdeg[i] == 1){
			end_nodes++;
			end_node = i;}
		if(outdeg[i] > 0 && start_node == -1){ start_node = i;} // if all deg are equal 
	}
	return ((end_nodes == 0 && start_nodes == 0) || 
			(end_nodes == 1 && start_nodes == 1));
}

void dfs(int v){
	// custom dfs to visit all edges
	while(outdeg[v] != 0){
		int u = adj[v][--outdeg[v]];
		dfs(u);
	}
	path.PB(v);
}

void heirholzers(){
    has_path = check();
	dfs(start_node);
	if(has_path && (int)path.size() == n+1){
	    reverse(ALL(path));
		retrive_path();
	}
	else cout << "NO" << "\n";
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);

	path.reserve((size_t) 2*(1e5+ 7));
	string in;
	int u ,v;
	cin >> n;
	for(int i = 0 ; i< n ; i++){
		cin >> in;
		u = construct(in.substr(0 ,2));
		v = construct(in.substr(1 ,2));
		adj[u].PB(v);
		indeg[v]++;
		outdeg[u]++;
	}
	heirholzers();

	return 0;
}
