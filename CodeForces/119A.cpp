
#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long

using namespace std;
int n ,a ,b ,c;
int dp[40001];

int solve(int n) {
	if (n == 0) return 0;
	if (n < 0) return INT_MIN;
	if (DP[n] != -1) return DP[n];
	DP[n] = max(1+solve(n-a) ,max(1+solve(n-b) ,1+solve(n-c)));
	return DP[n];
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	memset(DP ,-1 ,sizeof(DP));
	cin >> n >> a >> b >> c;
	cout << solve(n);

	
	return 0;
}