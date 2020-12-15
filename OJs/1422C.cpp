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
const ll MOD = 1e9 + 7;
// ll suf[MAXN] = {0};

void check(){
	string s;
	cin >> s;
	ll n = s.size();
	vector<ll> suf(n+1 ,0) ,suf_p10(n+1 ,0);
	ll p10 = 1 ,right_side = 0;
	for(int i = n-1 ; i >= 0 ;i--){
		right_side = (right_side + (s[i] - '0')*p10) % MOD;
		p10 = (p10 * 10)%MOD;
		suf[i] = (suf[i+1] + right_side)%MOD;
        // cout << MP(suf[i] ,right_side) <<"\n";
	}
	ll sum_p10 = 0;
	p10 = 1;
	for(int i = n-1 ;i >= 0 ; i--){
		suf_p10[i] = (suf_p10[i+1] + p10)%MOD;
		p10 = (p10 * 10)%MOD;
	}
	ll left_side = 0 ,ans = 0;
	for(ll i = 0 ;i < n ; i++){
// 		cout << MP(i ,left_side)<<"\n";
		ans = (ans + left_side * suf_p10[i])%MOD;
		left_side = (10*left_side + (s[i] - '0')) % MOD;
		ans = (ans + suf[i+1]) % MOD;
		
	}
	cout << ans;
// 	cout << suf << "\n" << suf_p10;
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
