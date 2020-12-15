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

ll n ,a[MAXN];
map<ll ,ll> adj[MAXN];

void check(){
	cin >> n;
	ll u ,v;
	for(ll i = 0 ; i + 1  < n ; i++){
		cin >> u >> v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	for(ll i = 0 ; i < n ; i++) cin >> a[i];

	ll j = 1 ;
	for(ll i = 0 ; i < n ; i++){
		while( adj[ a[i] ][ a[j] ] ) j++;
	}
	if( j != n || a[0] != 1 ){
		cout <<"NO\n";
	}else {
		cout << "YES\n";
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
