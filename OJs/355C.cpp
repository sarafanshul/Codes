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

ll pre[MAXN] ,n ,l ,r ,ql ,qr ,a[MAXN];

ll go(ll pl ,ll pr ,bool h ,ll tmp){
	if(pl > pr) return 0;
	ll ans = 0 ,t = pre[pr] ,p1 ,p2;
	t -= (pl ? pre[pl-1] : 0);

	if(h){
		p1 = l * t + (pr - pl + 1 + tmp)*ql;
		p2 = go(pl ,pr-1 ,h^1 ,0) + r*a[pr];
	}else{
		p1 = r * t + (pr - pl + 1 + tmp) * qr;
		p2 = go(pl+1 ,pr ,h^1 ,0) + l*a[pl];	
	}
	return min(p1 ,p2);
}

void check(){
	cin >> n >> l >> r >> ql >> qr;
	for(ll i = 0 ;i < n ;i++){
		cin >> a[i];
		if(!i) pre[i] = a[i];
		else pre[i] = pre[i-1] + a[i];
	}
	cout << min(go(0 ,n-1 ,0 ,-1) ,go(0 ,n-1 ,1 ,-1));
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