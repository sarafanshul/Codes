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

#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} modification(for redifination conflicts) after endif
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.x<<','<<p.y<<'>';return s;}
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p){return cout<<"("<<p.F<<", "<<p.S<<")";}
template<typename A> ostream& operator<<(ostream &cout,vector<A> const &v){cout<<"[";for(int i=0;i<v.size();i++){if(i)cout<<", ";cout<<v[i];}return cout<<"]";}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p){cin>>p.F;return cin>>p.S;}

const long long MAXN = 1e5 +7;

void check(){
    ll st[3] ,a[3] = {0} ,pr[3] ,r;
	string s;
	cin >> s;
	cin >> st[0] >> st[1] >> st[2];
	cin >> pr[0] >> pr[1] >> pr[2];
	for(int i = 0; i < s.size() ;i++){
		if(s[i] == 'B')a[0]++;
		else if(s[i] == 'S') a[1]++;
		else a[2]++;
	}
	
	auto price = [&](ll x){
		ll fb = max(x*a[0] - st[0] ,0LL);
		ll fs = max(x*a[1] - st[1] ,0LL);
		ll fc = max(x*a[2] - st[2] ,0LL);
		return (ll)(fb*pr[0] + fs*pr[1] + fc*pr[2]);
	};

	cin >> r;
	ll h ,l ,m ,z ,ans = 0;
	l = 0 ,h = r+1000 ,m = 0;
	while(l <= h){
		m = (l+h)/2;
		z = price(m);
		if(z == r){cout << m ;return;}
		if(z > r) h = m - 1;
		else l = m + 1 , ans = m;
	}
	cout << ans;
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
