#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=300, M=1e9+7;
int n, c[3];
//ll iv[mxN+1], dp[mxN+1][mxN+1][mxN+1];
long double dp[mxN+1][mxN+1][mxN+1];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i) {
		int ai;
		cin >> ai;
		++c[ai-1];
	}
	for(int k=0; k<=c[2]; ++k) {
		for(int j=0; j<=n; ++j) {
			for(int i=0; i<=n; ++i) {
				int tc=i+j+k;
				if(!tc||tc>n)
					continue;
				dp[i][j][k]=1;
				if(i)
					dp[i][j][k]+=dp[i-1][j][k]*i/n;
				if(j)
					dp[i][j][k]+=dp[i+1][j-1][k]*j/n;
				if(k)
					dp[i][j][k]+=dp[i][j+1][k-1]*k/n;
				dp[i][j][k]*=(long double)n/tc;
			}
		}
	}
	cout << fixed << setprecision(16) <<  dp[c[0]][c[1]][c[2]];
}