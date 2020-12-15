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

const long long MAXN = 1e5 +7;

vector<pair<ll ,ll>> adj[MAXN] ;
ll n ,mx_d = 0;

void dfs(ll v ,ll p ,ll d){
	mx_d = max(mx_d ,d);
	for( auto &[u ,w] : adj[v]){
		if (u ^ p){
			dfs(u ,v ,d + w);
		}
	}
}

void check(){
	cin >> n;
	ll u ,v ,w ,ans = 0;
	for(ll i = 0 ; i + 1 < n ; i++){
		cin >> u >> v >> w;
		adj[u].PB({v ,w});
		adj[v].PB({u ,w});
		ans += 2*w ; 
	}

	dfs(1 ,-1 ,0);

	cout << ans - mx_d <<'\n';
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
