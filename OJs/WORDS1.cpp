 
//https://www.spoj.com/problems/WORDS1/ 
 
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
const size_t MAXN = 1e6 +7;
int indeg[26] = {0} ,outdeg[26] = {0} ,adj[26][26];
bool pos[26] = {0} ,visited[26] = {0};
char s[1005];
int n ,m ;
 
void dfs(int v){
	visited[v] = 1;
	for(int u = 0 ; u < 26 ;u++){
		if((adj[v][u] || adj[u][v]) && !visited[u])
			dfs(u);
	}
}
 
void check(){
 
	bool exists = 1,connected = 1;
	memset(indeg ,0 ,sizeof(indeg));
	memset(outdeg ,0 ,sizeof(outdeg));
	memset(adj ,0 ,sizeof(adj));
	memset(pos ,0 ,sizeof(pos));
	memset(visited ,0 ,sizeof(visited));
	
	cin >> n;
	int ln;
	
	for(int i= 0; i < n ; i++){
		cin  >> s;
		ln = strlen(s);
		outdeg[s[0] - 'a']++;
		indeg[s[ln-1] - 'a']++;
		pos[s[0] - 'a'] = pos[s[ln-1] - 'a'] = 1;
		adj[s[0] - 'a'][s[ln-1] - 'a']++;
		adj[s[ln-1] - 'a'][s[0] - 'a']++;
	}
	int v;
	for(v = 0;!pos[v] ;v++);
	dfs(v);
 
	for(int j = 0; j < 26 ;j++){
		if(pos[j] && !visited[j]){connected = 0;break;}
	}
	int _st = -1 ,_ed = -1;
	if(connected){
		for(int i = 0; i < 26 ; i++){
			if(indeg[i] != outdeg[i]){
				if (_st == -1) _st = i;
				else if (_ed == -1) _ed = i;
				else exists = 0; }
		}
	}
 
	if(!connected || !exists){cout<<"The door cannot be opened.\n";return;}
	exists = 0;
	if(_st == -1) exists = 1;
	if((outdeg[_st] == indeg[_st]+1) && (indeg[_ed] == outdeg[_ed]+1)) exists = 1;		
	if((outdeg[_ed] == indeg[_ed]+1) && (indeg[_st] == outdeg[_st]+1)) exists = 1;
 
	if(exists) cout << "Ordering is possible.\n";
	else cout << "The door cannot be opened.\n";
}
 
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	
	int t = 0;
	cin >> t;
	while(t--){
		check();
	}	
 
	return 0;
}
 
