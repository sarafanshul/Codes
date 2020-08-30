

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

const int MAXN = 201;
int DP[MAXN][4];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(DP ,0x7f ,sizeof(DP));
	int n ,u ,v ,c;
    DP[0][0] = 0;DP[0][1] = 0;DP[0][2] = 0;DP[0][3] = 0;
	cin >> n;
	for(int i = 1; i <= n ; ++i){
		cin >> u;
		DP[i][0] = min(DP[i-1][1],min(DP[i-1][2],DP[i-1][0])) + 1;
		if (u == 1)
			DP[i][2] = min(DP[i-1][0] ,DP[i-1][1]);
		if (u == 2) 
			DP[i][1] = min(DP[i-1][0] ,DP[i-1][2]);
		if (u == 3){
			DP[i][2] = min(DP[i-1][0] ,DP[i-1][1]);
			DP[i][1] = min(DP[i-1][0] ,DP[i-1][2]);
		}
	}
// 	for(int i = 0; i <= n ; ++i){
// 	    for(int j = 0;j <= 3 ; ++j)cout << DP[i][j] << " ";
// 	    cout << "\n";
// 	}
	cout << min(DP[n][0] ,min(DP[n][1] ,DP[n][2])) << "\n";
	return 0;
}