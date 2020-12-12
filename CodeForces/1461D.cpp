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

vector<ll> a;
map<ll ,ll> mp;

void go(ll l ,ll r ,ll sm){
	mp[sm] = 1;
	if(a[l] == a[r]){
		return ;
	}

	ll mid = (a[l] + a[r]) / 2;
	ll suml = 0 ,j = l;
	while(a[j] <= mid) suml += a[j] ,j++;
	ll sumr = sm - suml;
	mp[suml] = 1;
	mp[sumr] = 1;

	go(l ,j-1 ,suml);
	go(j ,r ,sumr);
}

void check(){
	ll n ,q ,sm = 0;
	cin >> n >> q;
	a.assign(n ,0);
	mp.clear();

	for(ll i = 0 ; i < n ; i++){
		cin >> a[i];
		sm += a[i];
	}
	sort(ALL(a));
	go(0 ,n-1 ,sm);
	
	while(q--){
		ll x;
		cin >> x;
		cout << (mp.count(x) ? "YES" : "NO") << '\n';
	}
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
