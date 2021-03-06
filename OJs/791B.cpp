// The main observation is that you should print "YES" if the graph is a set of disjoint cliques 
// 		(in each connected non-clique there is a triple of vertices X,Y,Z that X-Y and Y-Z but not X-Z). 
// To check if each connected component is a clique, you can run dfs and count vertices and edges in the connected component � 
// 		it's a clique if and only if edges = (vertices)*(vertices-1)/2.

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
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;

#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} modification(for redifination conflicts) after endif
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}

const size_t MAXN = 2*(1e5 +7);
vector<ll> adj[MAXN];
ll n ,m ,ver ,edg;
bool vis[MAXN] = {0};

void dfs(int v){
	vis[v] = 1;
	ver++ ,edg+= adj[v].size();
	for(int u : adj[v]){
		if(!vis[u]) dfs(u);
	}
}

void check(){
	ll v ,u;
	cin >> n >> m;
	for(int i = 0;i < m; i++){
		cin >> v >> u;
		adj[v].PB(u);
		adj[u].PB(v);
	}
	for(int i = 1; i <= n ;i++){
		if(!vis[i]){
			ver = 0 ,edg = 0;
			dfs(i);
			if(edg != ver * (ver - 1)) {cout << "NO";return;}
		}
	}
	cout <<"YES";
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
