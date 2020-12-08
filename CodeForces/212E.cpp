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

const long long MAXN = 1e4 +7;

vector<ll> adj[MAXN] ;
ll n, sz[MAXN] = {0};

bitset<MAXN> can_split, dp;

void dfs(ll v ,ll p){
	sz[v] = 1;
	for(ll &u : adj[v]){
		if(u != p) {
			dfs(u ,v);
			sz[v] += sz[u];
		}
	}
}

void calc(ll v ,ll p ,ll totsz){
	vector<ll > vv;
	for(ll &u : adj[v]){
		if(u != p) vv.PB(sz[u]);
	}
	if(v != p) vv.PB(totsz - sz[v]);

	dp.reset();
	dp[0] = 1;

	for(ll &u : vv) dp |= (dp << u);

	can_split |= dp;
	
	for(ll &u : adj[v]){
		if(u != p)
			calc(u ,v ,totsz);
	}
}

void check(){
	cin >> n;
	ll u ,v;
	for(ll i = 0 ; i + 1 < n ; i++){
		cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	dfs(1 ,-1);

	calc(1 , 1 , sz[1]);

	cout << (ll)can_split.count() - 2 <<'\n';
	for(ll i = 1 ; i + 1 < n ; i++){
		if( can_split[i] ) cout << i << ' ' << n - i - 1 << '\n';
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
