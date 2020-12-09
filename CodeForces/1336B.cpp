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
ll ans;

inline ll sq(ll x){return x*x; }

void go(vector<ll>& a ,vector<ll>& b ,vector<ll>& c){
	for(const ll &x : a){
		auto y = lower_bound(ALL(b) , x );
		auto z = upper_bound(ALL(c) , x );
		if(y == b.end() || z == c.begin()) continue;
		z--;
		ans = min( ans , sq(x - *y) + sq(*y - *z) + sq(*z - x) );
	}
}

void check(){
	ll nr ,ng ,nb;
	cin >> nr >> ng >> nb;
	vector<ll> r(nr) ,b(nb) ,g(ng);

	for(ll i = 0 ; i < nr ; i++) cin >> r[i];
	for(ll i = 0 ; i < ng ; i++) cin >> g[i];
	for(ll i = 0 ; i < nb ; i++) cin >> b[i];

	sort(ALL(r));
	sort(ALL(g));
	sort(ALL(b));
	
	ans = LONG_LONG_MAX;

	go(r ,g ,b);
	go(r ,b ,g);
	go(g ,r ,b);
	go(g ,b ,r);
	go(b ,g ,r);
	go(b ,r ,g);

	cout << ans <<'\n';
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
