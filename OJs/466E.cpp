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

ll spar[MAXN], par[MAXN], packet[MAXN], packet_par[MAXN];

ll find(ll v) {
	return v == par[v] ? v : par[v] = find(par[v]);
}
void join(ll u, ll v) {
	spar[u] = v;
	u = find(u), v = find(v);
	par[u] = v;
}

void check(){
	ll n ,m;
	cin >> n >> m;
	for(ll i = 1 ; i <= n ; i++) par[i] = i;
	ll idx = 0;

	while(m -- ){
		ll t ,x ,y;
		cin >> t;
		if(t == 1){
			cin >> x >> y;
			join(x ,y);
		}else if(t == 2){
			cin >> x;
			packet[ ++idx ] = x;
			packet_par[idx] = find(x);
		} else{
			cin >> x >> y;
			ll cur = packet[y];
			while(cur != packet_par[y] && cur != x) cur = spar[cur];

			cout << (cur == x ? "YES\n" : "NO\n");
		}
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
