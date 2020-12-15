// pragma for fast runtime optimization
// // #pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma") 
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

// header(s)
#include <bits/stdc++.h>

// custom aliases
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define MP make_pair
// // for overflow
#define int long long
// #define MAX LONG_LONG_MAX
// #define MIN LONG_LONG_MIN

// namespaces
using namespace std;

// global declerations
const size_t MAXN = 1e5 +7;

int dp[207][207][207];
int n ,k;
string s ,t;
int go(int pos ,int nT0 ,int k){
	if(pos >= s.size()) return 0;
	if(dp[pos][nT0][k] != -1) return dp[pos][nT0][k];
	
	long long ans = 0;
	ans = max(ans ,go(pos+1 ,nT0 ,k));

	// make T0
	int cost = (s[pos] == t[0])?0:1;
	if(k >= cost){
		ans = max(ans ,go(pos+1 ,nT0+1 ,k-cost));
	}
	// make T1
	cost = (s[pos] == t[1]?0:1);
	if(k >= cost){
		ans = max(ans ,nT0+go(pos+1 ,nT0 ,k-cost));
	}
	dp[pos][nT0][k] = ans;
	return dp[pos][nT0][k];
}

void check(){
	cin >> n >> k;
	cin >> s;
	cin >> t;
	if(t[0] == t[1]){
		int count = 0;
		for(auto c : s){if(c == t[0])count++;}
			count += k;
		count = min(count ,n);
		cout << count*(count-1)/2 <<"\n";
	}
	else {
		memset(dp ,-1, sizeof(dp));
		cout << go(0 ,0 ,k);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); 
	cin.exceptions(cin.failbit);

	int t;
// 	cin >> t;
    t = 1;

	while(t--){
		check();
	}

	return 0;
}
