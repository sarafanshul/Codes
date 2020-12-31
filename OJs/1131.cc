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

vector<ll> adj[MAXN];
vector<ll>dist;
ll n ;

void bfs(ll v) {
	dist.assign( n+1 , -1 );
	dist[v] = 0;
	queue<ll> q;
	q.push(v);
	while(!q.empty()){
		v = q.front();q.pop();
		for(ll &u :adj[v]){
			if(dist[u] == -1){
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
} 

pair<ll ,ll> farthest(){
	ll _max = -1 ,node = -1;
	for(ll i = 0 ;i <= n ;i++) 
		if(dist[i] > _max) {_max = dist[i];node = i;}
	return MP(node ,_max);
}

ll get_diameter(){
	bfs(0);
	auto last = farthest() ;
	bfs(last.F);
	return farthest().S ;
}

void check(){
	cin >> n;
	for(ll i = 0 ; i + 1 < n ; i++){
		ll u , v;
		cin >> u >> v  ; u-- , v-- ;
		adj[u].PB(v) ;
		adj[v].PB(u) ;
	}
	cout << get_diameter() <<'\n';
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
