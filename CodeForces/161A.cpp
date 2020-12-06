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

void check(){
	ll n ,m ,x ,y;
	cin >> n >> m >> x >> y;
	vector<pair<ll ,ll> > a(n);
	set<pair<ll ,ll> > b;
	for(ll i = 0 ; i < n ; i++) cin >> a[i].F ,a[i].S = i;

	ll tmp;
	for(ll i = 0 ; i < m ; i++){
		cin >> tmp;
		b.insert(MP(tmp ,i));
	}
	vector<pair<ll ,ll>> ans;
	sort(ALL(a));

	for(ll i = 0 ; i < n ;i++){
		ll cur = a[i].F;
		auto lb = b.lower_bound(MP(cur - x , -1));

		if(lb == b.end()) continue;
		if((*lb).F > cur + y) continue;
		ans.PB( { a[i].S ,(*lb).S } );
		print(*lb ,a[i]);
		b.erase(lb);
	}
	cout << ans.size() <<'\n';
	for(auto &[i ,j] : ans) cout << i+1 << ' '<< j+1 <<'\n';
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
