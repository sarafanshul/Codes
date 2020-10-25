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
	string s;
	cin >> s;
	ll a[3] = {0};
	for(ll i = 0 ;i < s.size() ;i++){
		if(s[i] == 'B')a[0]++;
		else if(s[i] == 'S')a[1]++;
		else a[2]++;
	}
	ll nb ,ns ,nc ,cost ,pb ,ps ,pc;
	cin >> nb >> ns >> nc;
// 	ll ans = min( {nb/a[0] ,ns/a[1] ,nc/a[2]} );
// 	nb -= ans*a[0] ,ns -= ans*a[1] ,nc -= ans*a[2];
	
	cin >> pb >> ps >> pc >> cost;
	
	auto how_m = [&](ll c) -> ll {
		ll br = max(0LL ,a[0]*c - nb);
		ll sc = max(0LL ,a[1]*c - ns);
		ll ch = max(0LL ,a[2]*c - nc);

		ll pr = br*pb + sc*ps + ch*pc;
		return pr;
	};

	ll l = 0 ,r = cost+10000 ,m ,pre = 0 ,buyn = 0;
	while(l < r){
		m = (l+r)/2;
		ll tot = how_m(m);
// 		cout << MP(tot ,m) <<"  ";
		if(cost == tot){buyn = m ;break;}
		if(tot > cost) r = m;
		else l = m+1 ,buyn = m;
	}
	cout << buyn;
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
