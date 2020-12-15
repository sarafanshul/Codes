#pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
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
#define double long double
#define MP make_pair
// #define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

using namespace std;


#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}
#endif

const long long MAXN = 1e5 +7;

void check(){
	ll n ,x;
	cin >> n >> x;
	vector<pair<ll ,pair<ll ,ll>>> a(n);
	vector<pair<ll ,ll>> id(n);
	for(int i = 0 ; i < n ;i++) cin >> a[i].S.F >> a[i].S.S >> a[i].F;
	sort(ALL(a));
	for(int i = 0 ; i < n ;i++){
		id[i].F = a[i].S.S - a[i].S.F + 1;
		id[i].S = i;
	}
	sort(ALL(id));
	ll ans = 10000000LL;
	
	auto can = [&](ll u , ll v){
	   // cout << MP(id[u].S ,id[v].S) <<" " << MP(a[id[u].S].S.F ,a[id[v].S].S.F) <<"\n";
		return (a[id[u].S].S.S < a[id[v].S].S.F) || (a[id[v].S].S.S < a[id[u].S].S.F);
	};

	auto find_m = [&](ll fr ,ll days){
		auto idx = lower_bound(ALL(id) ,MP(days ,0LL)) - id.begin();
		for(idx; idx < n ;idx++){
			if(id[idx].F != days)break;
			if(can(fr ,idx)){ return idx; }
		}
		return -1LL;
	};

	for(int i = 0 ;i < (n/2)+1 ;i++){
		ll sm1 = a[id[i].S].F;
		ll dy = id[i].F;
		ll f = find_m(id[i].S ,x-dy);
// 		cout <<f;
		if(f == -1)continue;
		sm1 += a[id[f].S].F;
		ans = min(sm1 ,ans);
	}
	cout << (ans == 10000000LL ? -1 : ans);
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	// cin.exceptions(cin.Failbit);
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){
		// cout << "Case "<< i << ":\n";
		check();
	}
	return 0;
}
