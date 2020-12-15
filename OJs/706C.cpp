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

ll a[MAXN] ,cache[MAXN][2] ,n;
string s[MAXN][2];

template<typename T = long long >
T go(T idx ,T rev){
	if(idx == n+1) return 0LL;
	ll &ans = cache[idx][rev];
	if(ans != -1) return ans;

	ans = 1e15;
	if(s[idx][0] >= s[idx-1][rev])
		ans = min(ans ,go(idx+1 ,0LL));
	if(s[idx][1] >= s[idx-1][rev])
		ans = min(ans ,a[idx] + go(idx+1 ,1LL));
	return ans;
}

void check(){
	memset(cache ,-1 ,sizeof(cache));
	cin >> n;
	for(int i = 1 ;i <= n ;i++) cin >> a[i];
	for(int i = 1 ;i <= n ;i++){
		cin >> s[i][0];
		s[i][1] = s[i][0];
		reverse(ALL(s[i][1]));
	}
	ll ans = min(go(2LL ,0LL) ,a[1] + go(2LL ,1LL));
	cout << (ans >= 1e14 ? -1 :ans);
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
