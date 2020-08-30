
/*
This problem can be solved by dinamic programming.
Let's Dp[n][is] — number of ways with length equals to n in k-tree, 
where if is = 1 — there is exists edge with length at least d, 
is = 0 — lengths of all edges less then d.

Initial state Dp[0][0] = 1.
Transition — iterate all edges which can be first on the way in k-tree, 
then problem transform to the same, but with less length of the way 
(because subtree of vertex son is the k-tree).

Dp[n][0] = Dp[n-1][0] + ... + Dp[n-min(d-1,n)][0] 

Dp[n][1] = Dp[n-1][1] + ... + Dp[n-min(d-1,n)][1] 
				+ (Dp[n-d][0] + Dp[n-d][1]) + ... 
				+ (Dp[n-min(n,k)][0] + Dp[n-min(n,k)][1])
*/

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
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 107;

int dp[MAX][3];

inline void add(int &a ,int b){a = (a+b >= MOD)?(a+b-MOD):a+b;}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n ,k ,d;
	cin >> n >> k >> d;
	dp[0][0] = 1;
	dp[1][0] = 0;

	for(int i = 1; i <= n ;i++){
		dp[i][0] = dp[i][1] = 0;
		for(int j = 1; j <= k ;j++){
			if(i-j < 0)break;
			if(j < d){
				add(dp[i][0] ,dp[i-j][0]);
				add(dp[i][1] ,dp[i-j][1]);
			}else {
				add(dp[i][1] ,dp[i-j][0]);
				add(dp[i][1] ,dp[i-j][1]);
			}
		}
	}
	cout << dp[n][1];

	return 0;
}