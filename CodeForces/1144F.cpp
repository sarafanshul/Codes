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

const long long MAXN = 2e5 +7;

vector<ll > adj[MAXN] ,level(MAXN ,0);
ll n ,m;
bool ans[MAXN] = {0} ,vis[MAXN] = {0};

void dfs(ll v ,ll p){
	level[v] = level[p] + 1;
	vis[v] = 1;
	for(auto &u : adj[v]){
		if( !vis[u]) dfs(u ,v);
	}
}

void check(){
	cin >> n >> m;
	ll u ,v;
	vector<pair<ll ,ll>> a(m+1);
	for(ll i = 1 ; i <= m ; i++){
		cin >> u >> v;
		adj[u].PB( v );
		adj[v].PB( u );
		a[i] = MP(u ,v);
	}
	level[0] = 0;
	dfs(1 ,0);

	for(ll i = 1 ; i <= m ; i++){
		u = a[i].F ,v = a[i].S;
		print(i ,level[u] ,level[v]);
		if(level[ v ] % 2 == level[ u ] % 2 ){
			cout << "NO\n";
			return;
		}
		if(level[u] % 2) ans[i] = 1;
		else ans[i] = 0;
	}

	cout << "YES\n";
	for(ll i = 1 ; i <= m; i++){
		cout << ans[i];
	}
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
