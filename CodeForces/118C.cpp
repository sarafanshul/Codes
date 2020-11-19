// #pragma GCC optimize("Ofast")  // remove in mingw32 bit ;
// #pragma GCC target("avx,avx2,fma") 
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("unroll-loops")
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
	ll n ,k;
	cin >> n >> k;
	ll df[10][10] = {0} , cnt[10] = {0} ,mn[10] = {0};
	string s;
	cin >> s;
	for(ll i = 0 ; i < n ;i++){cnt[ s[i] - '0' ]++;}
	for(ll i = 0 ;i < 10 ;i++){
		for(ll j = 0 ;j < 10 ;j++){df[i][abs(i - j)] += cnt[j];}
	}
	for(ll i = 0 ; i < 10 ; i++){
		ll x = k ,v = 0;
		x -= cnt[i];
		for(ll j = 1 ; (j < 10 && x >= 0 ) ;j++){
			if(x > df[i][j]) v += df[i][j]*j ,x -= df[i][j];
			else v += x*j ,x = 0;
		}
		if(x > 0)mn[i] = MAXN;
		else mn[i] = v;
	}
	ll p[10] = {0};
	for(ll i = 0; i < 10 ;i++) p[i] = i;
	auto cmp = [&](const ll x ,const ll y) -> bool {return mn[x] < mn[y];};
	sort(p ,p+10 ,cmp);
	vector<pair<ll ,ll>> ret;
	for(ll i = 0 ;i < 10 ;i++){if(mn[p[i]] == mn[p[0]])ret.PB(MP(p[i] ,mn[p[i]]));}
	sort(ALL(ret));
    cout << ret[0].S<<"\n";
    ll to = ret[0].F;
    ll x = k - cnt[to];
    for(ll w = 1 ; w < 10 ;w++){
        ll j1 = to - w ,j2 = to + w;
        if(j2 > to ){ // left - r;
            for(ll z= 0 ;(z < n && x > 0);z++){if(((s[z] - '0') == j2)) x-- ,s[z] = to +'0';}
        }else {
            for(ll z= n - 1 ;(z >= 0 && x > 0);z--){if(((s[z] - '0') == j2)) x-- ,s[z] = to +'0';}
        }
        if(j1 > to){ // left - r;
            for(ll z= 0 ;(z < n && x > 0);z++){if(((s[z] - '0') == j1)) x-- ,s[z] = to +'0';}
        }else {
            for(ll z= n - 1 ;(z >= 0 && x > 0);z--){if(((s[z] - '0') == j1)) x-- ,s[z] = to +'0';}
        }
    }
    cout << s;
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
