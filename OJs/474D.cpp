/*
This is similar to the linear solution for the fibonacci sequence. 
	DP[i] = DP[i-1] + DP[i-k]. 
Either the last flower is red ( => DP[i-1] ) or its white ( => DP[i-k] ).

*/
#include <bits/stdc++.h>

#define ALL(x) x.begin(),x.end()
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define ll long long
// #define int long long
using namespace std;

const int MOD = 1000000007;
const int MAXAB = 500007;
inline bool sgn(int x){return (x>0)?1:0;}
inline int mod(int a ,int b){return ((a+b)>= MOD)?(a+b-MOD):a+b;}

int dp[MAXAB], pre[MAXAB];

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t ,k ,a ,b ,ans;
	cin >> t >>k;
	for(int i = 0; i <k ;i++){
		dp[i] = 1;
		pre[i] = i+1;
	}
	for(int i = k; i < MAXAB; i++){
		dp[i] = mod(dp[i-1] ,dp[i-k]);
		pre[i] = mod(pre[i-1] ,dp[i]);
	}
	while(t--){
		cin >> a >>b ;
		ans = pre[b] - pre[a-1];
		ans += (ans < 0 ? MOD : 0);
		cout << ans <<"\n";
	}
	return 0;
}