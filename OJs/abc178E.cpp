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
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN
#ifdef LOCAL // setting up print debugging (yes lol)
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
using namespace std;

const size_t MAXN = 2*(1e5 +7);

pair<ll ,ll> a[MAXN];

void check(){
	ll n;
	cin >> n;
	for(ll i =0 ; i < n ; i++){
		cin >> a[i].F >> a[i].S;
	}
	sort(a ,a+n);
	ll ans = 0LL;

	ll mxabve = -a[0].F + a[0].S;
	ll mnbelow = a[0].F + a[0].S;

	for(ll i = 1; i < n; i++){
		ans = max({ans ,a[i].F-a[i].S+mxabve ,a[i].F+a[i].S-mnbelow});
		mxabve = max(mxabve ,-a[i].F + a[i].S);
		mnbelow = min(mnbelow ,a[i].F + a[i].S); 
	}
	cout << ans;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
