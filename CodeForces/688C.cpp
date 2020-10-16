#pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
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
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;


#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}
#endif

#define int long long
const long long MAXN = 1e5 +7;

int n ,m;
vector<vector<int>> adj(MAXN ,vector<int>());

vector<int> side(MAXN, -1);
bool is_bipartite = true;
queue<int> q;

bool is_bip(){
	for (int st = 0; st < n; ++st) {
    	if (side[st] == -1) {
        	q.push(st);
        	side[st] = 0;
        	while (!q.empty()) {
            	int v = q.front();
            	q.pop();
            	for (int u : adj[v]) {
                	if (side[u] == -1) {
                    	side[u] = side[v] ^ 1;
                    	q.push(u);
                	} else {
                    	is_bipartite &= side[u] != side[v];
                	}
            	}
        	}
    	}
	}
	return is_bipartite;
}

void check(){
	ll u ,v;
	cin >> n >> m;
	bool vis[MAXN] = {0};
	for(int i = 0 ;i < m ;i++){
		cin >> v >> u;
		adj[v].PB(u);
		adj[u].PB(v);
		vis[u] = 1 ,vis[v] = 1;
	}
	if(!is_bip()){cout <<"-1";return;}
	ll a[2] = {0};
	for(int i = 1; i <= n ;i++)if(vis[i])a[side[i]]++;
	
	cout << a[0] <<"\n";
	for(int i = 1 ; i<= n ;i++)if(!side[i] && vis[i]) cout << i<<" ";
    cout << "\n";
	cout << a[1] <<"\n";
	for(int i = 1 ; i<= n ;i++) if(side[i] && vis[i]) cout << i<<" ";

}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
