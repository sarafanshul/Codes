#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long;

using namespace std;
const int MOD = 1e9+7;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >>n;
	vector<int>dp(n+1 ,0);
	dp[0] = 1;
	for(int i = 1 ; i <= n; i++){
		for(int j = 1; j <= 6 && i-j >= 0 ;j++){
			dp[i] = ((dp[i]+dp[i-j]) >= MOD) ? (dp[i]+dp[i-j]) - MOD : (dp[i]+dp[i-j]);
		}
	}
	cout << dp[n] <<"\n";

	return 0;
}
