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
const unsigned MAXN = 1007;

int n ,m;
int dp[MAXN][MAXN];
string grid[MAXN];

inline int mod(int a ,int b){return (a+b >= MOD)?(a+b-MOD):(a+b);}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n; 
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) cin >> grid[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                if (i > 0) dp[i][j] = mod(dp[i][j] , dp[i-1][j]);
                if (j > 0) dp[i][j] = mod(dp[i][j] , dp[i][j-1]);
            } else dp[i][j] = 0;
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}