#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

const long long MAXN = 2e2 +7;

ll n ,m ,k;
bool vis[MAXN];
vector<set<ll>> adj(MAXN);
string ans ;

void dfs(char v){
	ans += v;
	vis[v] = 1;
	for(auto u : adj[v]) if(!vis[u]) dfs(u);
}

void check(){
	memset( vis ,false ,MAXN );
	adj.clear(); adj.resize(MAXN);
	ans.clear();
	string s; 
	cin >> s;

	bool f = 0;
	for(ll i = 1 ; i < s.size() ; i++){
		adj[ s[i] ].insert( s[i - 1] );
		adj[ s[i - 1] ].insert( s[i] );
		if(adj[ s[i] ].size() > 2 || adj[ s[i - 1] ].size() > 2) f |= 1;
	}
	if(f){
		cout << "NO\n";
		return ;
	}
	for(ll i = 'a' ; i <= 'z' ; i++){
		if(adj[i].size() != 2 && !vis[i])
			dfs(i);
	}
	if(ans.size() != 26){
		cout << "NO\n";
		return ;
	}
	cout << "YES\n" <<ans <<'\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
