#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
#define int long long
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e6+7;

int dp[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i = 0 ; i< n; i++){
		cin >> a[i];
	}
	dp[0] = 0;
	for(int i = 1; i <= x; i++){
		dp[i] = INT_MAX;
		for(int c : a) 
			if (i - c >= 0)
				dp[i] = min(dp[i] ,dp[i-c]+1);
	}
	cout << ((dp[x] == INT_MAX)?-1:dp[x]);

	return 0;
}
