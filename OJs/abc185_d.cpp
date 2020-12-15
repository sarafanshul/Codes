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
template<typename T = long long >
inline T __ceil(T a ,T b){return (a + b - 1)/b;}

void check(){
	ll n ,m ,x;
	cin >> n >> m;
	vector<ll> a = {0 ,n+1 };
	for(ll i = 0 ; i < m ; i++){
		cin >> x;
		a.PB(x);
	}
	sort(ALL( a ));
	print(a ,a.size());
	ll mn = 1e10 , df = 0;
	
	for(ll i = 1 ; i < a.size() ; i++ ){
		if(a[i] == a[i-1] + 1)continue;
		mn = min(mn ,a[i] - a[i-1] - 1);
		df += a[i] - a[i - 1] - 1;
	}

	ll ans = 0;
	for(ll i = 1 ; i < a.size() ; i++ ){
		if(a[i] == a[i-1] + 1)continue;
		ans += __ceil(a[i] - a[i - 1] - 1 ,mn);
	}
	
	cout << ans <<'\n';
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
