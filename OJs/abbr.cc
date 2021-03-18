#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define F first
#define S second
#define ll long long
#define double long double
#define MP make_pair

using namespace std;

#ifdef CUST_DEBUG
template<class K, class V>ostream& operator<<(ostream&s,const pair<K,V>&p){s<<'<'<<p.F<<','<<p.S<<'>';return s;}
template<class T, class=typename T::value_type, class=typename enable_if<!is_same<T,string>::value>::type>
ostream& operator<<(ostream&s,const T&v){s<<'[';for(auto&x:v){s<<x<<", ";}if(!v.empty()){s<<"\b\b";}s<<']';return s;}
void __prnt(){cerr<<endl;} template<class T, class...Ts>void __prnt(T&&a,Ts&&...etc){cerr<<a<<' ';__prnt(etc...);}
#define print(...) __prnt(__VA_ARGS__)
#else
#define print(...)
#endif

const long long MAXN = 1e3 +7;

bool check1(){
	string a , b ;
	cin >> a >> b ;
	ll n = a.size() , m = b.size() ;
	bool dp[MAXN][MAXN] = {0} ;
	dp[0][0] = 1 ;

	for(ll i = 1 ; ( i <= n && islower(a[i-1]) ) ; i++)
		dp[i][0] = 1;
	for(ll i = 1 ; i <= n ; i++ ){
		for(ll j = 1 ; j <= m ; j++ ){
			if( islower(a[i-1]) && dp[i-1][j] )
				dp[i][j] = 1 ;
			if( dp[i-1][j-1] && (toupper(a[i-1]) == b[j-1] || a[i-1] == b[j-1]) )
				dp[i][j] = 1 ;   
		}
	}
	return dp[n][m] ;
}

void check(){
	cout << ( check1() ? "YES" : "NO" ) << '\n' ;
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	cin >> t;
	for(int i = 1 ; i <= t ;i++){ print("Case : " , i) ; check(); }
	return 0;
}
