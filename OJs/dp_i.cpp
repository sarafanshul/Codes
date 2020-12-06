/*
Let f(i, j) be the probability of getting exactly i heads among the first j coins. 

We have two possibilities for the j-th coin. 

Case 1 - It is a heads. 

The probability of getting a head is p[j]. 

And we need to get exactly (i - 1) heads from the previous (j - 1) coins. 

This is given by p[j] x f(i - 1, j - 1)

Case 2 - It is tails

The probability is given by (1 - p[j])

We need i heads from the first j - 1 coins. 

The probability is (1 - p[j]) x f(i, j - 1)

The base case is that f(0, 0) = 1. 

------

To get the answer we need to sum over all f(i, N) where i > N/2.

----------
*/
#ifndef CUST_DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
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

const long long MAXN = 3e3 +7;

double P[MAXN] ,dp[MAXN][MAXN] = {0} ;

void check(){
	ll n;
	cin >> n;
	for(ll i = 0 ; i < n ; i++){
		cin >> P[i];
	}
	dp[0][0] = 1;
	for(ll i = 0 ; i < n ; i++){
		for(ll j = 0 ; j <= i ; j++){
			dp[i + 1][j + 1] += dp[i][j] * P[i]; // if heads;
			dp[i + 1][j] += dp[i][j] * (1 - P[i]); // if tails;
		}
	}
	double ans = 0;
	for(ll i = (n + 1) / 2 ; i <= n ; i++){
		ans += dp[n][i];
	}
	cout << fixed << setprecision(10) << ans << '\n';
}

int32_t main(){
	#ifndef CUST_DEBUG
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#endif
	int t = 1;	
	// cin >> t;
	for(int i = 1 ; i <= t ;i++){ check(); }
	return 0;
}
