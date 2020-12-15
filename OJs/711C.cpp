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

const long long MAXN = 1e2 +7;
#define int long long

const int INF = 1e18 + 7;
int n ,m ,k;
int a[MAXN] ,pri[MAXN][MAXN] ,dp[MAXN][MAXN][MAXN];

//      index   ,previous ,beauty
int go(int idx ,int prev ,int sm){
	if(idx == n+1) {
		if(sm == k)return 0LL;
		return INF;
	}
	int &ret = dp[idx][prev][sm];
	if(ret != -1)return ret;

	ret = INF;
	bool is = (a[idx] == 0);
	if(is){
		for(int i = 1 ;i <= m ;i++){
			if(prev == i){
				ret = min(ret ,pri[idx][i] + go(idx+1 ,i ,sm));
			}else{
				ret = min(ret ,pri[idx][i] + go(idx+1 ,i ,sm+1));
			}
		}
	}else{
		if(prev == a[idx]){
			ret = go(idx+ 1 ,a[idx] , sm);
		}else {
			ret = go(idx+1 ,a[idx] ,sm+1);
		}
	}
	return ret;
}

void check(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n ;i++) cin >> a[i];

	for(int i = 1; i <= n ;i++){
		for(int j = 1 ; j<= m ;j++){
			cin >> pri[i][j];
		}
	}
	for(int i = 0 ;i < MAXN ;i++)
		for(int j = 0 ;j < MAXN ;j++)
			for(int k = 0 ;k < MAXN ;k++) dp[i][j][k] = -1LL;

	int ans = go(1 ,0 ,0);

	cout << (ans >= INF ? -1 : ans) <<'\n';
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
