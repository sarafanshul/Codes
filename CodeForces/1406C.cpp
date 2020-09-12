#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
using namespace std;

const size_t MAXN = 1e5 +7;


void check(){
	int n;
	cin >> n;
	vector<vector<int>> adj(n+1 ,vector<int>(0));
	int in[n+1] = {0} ,out[n+1] = {0} ,par[n+1];
	// 1 based indexing
	for(int i = 0; i < n-1; i++){
		cin >> v >> u;
		adj[v].PB(u);adj[u].PB(v);
		in[u]++;out[v]++;
		par[u] = v;
	}
	queue<int> q;
	int l1 = -1 ,l2 = -1;
	int ad1 = 0 ,ad2 = 0;
	for(int i = 1; i <= n ;i++) if(out[i] == 0)q.push(i);
	for(int i = 1; i <= n ;i++) 
		if(out[i] == 0){
			if (!ad1) ad1 = i;
			if (!ad2){
				if(par[ad1] != par[ad2]) ad2 = i;
			}
		}
	int n1 = n;
	while(!q.empty()){
		v = q.front();q.pop();
		n1--;
		out[par[v]]--;
		for(int i = 1; i <= n ;i++) if(out[i] == 0)q.push(i);
		if(q.size() == 1){
			cout << l1<<" " << l2<<"\n";
			cout << l1<<" " << l2<<"\n";
			return;
		}
		if((q.size() == 2) && (n - n1 == 2)){
			cout << ad1 << " " << par[ad1] << "\n";
			cout << par[ad2] << " " << ad1 << "\n";
			return;			
		}
		l1 = v;l2 = par[v];
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t;	cin >> t;
	while(t--)check();
	return 0;
}
