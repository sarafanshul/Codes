#pragma GCC optimize("Ofast")  
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

#ifdef CUST_DEBUG // </COMMENT> the {ostream operator} MODification(for redifination conflicts) after endif
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

const size_t MAXN = 1e5 +7;
const ll MOD = 998244353;
struct mint {
  	ll x; // typedef long long ll;
  	mint(ll x=0):x((x%MOD+MOD)%MOD){}
  	mint operator-() const { return mint(-x);}
  	mint& operator+=(const mint a) {
    	if ((x += a.x) >= MOD) x -= MOD;
    	return *this;
  	}
  	mint& operator-=(const mint a) {
	  if ((x += MOD-a.x) >= MOD) x -= MOD;
    	return *this;
  	}
	mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
    	if (!t) return 1;
    		mint a = pow(t>>1);
    		a *= a;
    		if (t&1) a *= *this;
    		return a;
  		}

  	// for prime MOD
  	mint inv() const { return pow(MOD-2);}
  	mint& operator/=(const mint a) { return *this *= a.inv();}
  	mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}


void check(){
	int n, k;
	cin >> n >> k;
	#define int long long
	vector<pair<int,int>> in(k);
	for(pair<int,int>& p : in) {
		cin >> p.F >> p.S ;
	}

	vector<int> dp(n), pref(n);
	dp[0] = pref[0] = 1;
	
	for(int i = 1; i < n; ++i) {
		for(pair<int,int> p : in) {
			int L = max(0LL, i - p.S);
			int R = i - p.F;
			if(L <= R) {
				// dp[i] += pref[R] - pref[L-1];
				dp[i] += pref[R];
				if(L >= 1) dp[i] -= pref[L-1];
				dp[i] %= MOD;
				if(dp[i] < 0) dp[i] += MOD;
				// for(int j = L; j <= R; ++j) {
					// dp[i] += dp[j];
				// }
			}
		}
		pref[i] = (pref[i-1] + dp[i]) % MOD;
	}
	cout << dp[n-1];
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
