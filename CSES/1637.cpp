#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
// #define int long long

using namespace std;

const int MOD = 1e9+7;
const uint32_t MAXN = 1e6+7;
const uint32_t MAXM = 101;


inline int mod(int a ,int b){return (a+b >= MOD)?(a+b-MOD):(a+b);}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, target;
    cin >> n >> target;
    vector<int> x(n);
    for (int&v : x) cin >> v;

    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-x[i-1];
            if (left >= 0) {
            dp[i][j] =mod(dp[i][j] ,dp[i][left]);
            }
        }
    } 
    cout << dp[n][target];
    return 0;
}