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

const long long MAXN = 2e6 +7;

double get_dist(ll x1 ,ll y1 ,ll x2 ,ll y2){
	return sqrt( (double)(x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) );
}

void check(){
	ll a[2] ,m[2] ,t[2] ,n ,idx_a = -1 ,idx_m = -2;
	cin >> a[0] >> a[1] >> m[0] >> m[1] >> t[0] >>t[1] >> n;
	pair<double ,ll> da[MAXN] ,dm[MAXN];
	double dt[n] ,ans = 0;
	ll x ,y;
	for(ll i = 0 ; i < n ;i++){
		cin >> x >> y;
		dt[i] = get_dist(x ,y ,t[0] ,t[1]);
		da[i] = MP(get_dist(x ,y ,a[0] ,a[1]) - dt[i] ,i);
		dm[i] = MP(get_dist(x ,y ,m[0] ,m[1]) - dt[i] ,i);
		ans += 2*dt[i];
	}

	sort(da ,da+n);sort(dm ,dm+n);

	if(da[0].S != dm[0].S) 
	    ans += min({ da[0].F ,dm[0].F ,da[0].F + dm[0].F });
	else 
	    ans += min({ da[0].F+dm[1].F ,da[1].F+dm[0].F ,da[0].F ,dm[0].F});

	cout << fixed << setprecision(12)<< ans <<"\n";
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
