#ifndef CUST_DEBUG
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") 
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
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
 
const long long MAXN = 10009;
 
const ll INF = 1e18;
vector<pair<ll ,ll>> adj[MAXN] ;
vector<ll> d ;
ll n ;
 
void dijkstra(ll s) {
	d.assign(n + 1, INF); d[s] = 0;
	using pii = pair<ll, ll>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, s});
	while (!q.empty()) {
		ll v = q.top().second ,d_v = q.top().first; q.pop();
		if (d_v != d[v]) continue;
		for (auto &[to ,len] : adj[v]) {
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				q.push({d[to], to});
			}
		}
	}
}
 
void check(){
	unordered_map<string ,ll > mp;
	cin >> n;
	for(ll i = 0 ; i < n ; i++){
		string s;
		cin >> s;
		mp[s] = i;
		ll v ,w , x;
		cin >> x;
		for(ll j = 0 ; j < x ; j++){
			cin >> v >> w;
			v-- ;
			adj[i].PB( {v ,w} );
		}
	}
	ll q ;
	cin >> q; 
	while(q--){
		string  fr ,to ;
		cin >> fr >> to ;
		dijkstra( mp[fr] ) ;
		// print(d) ;
		if(d[ mp[to] ] != INF) cout << d[ mp[to] ] <<'\n';
		else cout << "-1\n" ;
	}
	for(ll i = 0 ; i < MAXN ; i++) adj[i].clear() ;
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
 