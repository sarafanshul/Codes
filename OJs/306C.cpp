/*
Note that a junction can be happy only when the number of colors 
is at least the number of leaves in it. 
The rule is that this is the only condition needed: indeed, 
 if we color the leaves cyclically in the order of Euler tour, 
 all such junctions will be happy. So the answer for the number
 of colors is simply the number of junctions that have at most c
  leaves in the subtree
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
#define ll long long;
using namespace std;

// const int MAXN = 200001;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	const int MAXN = 105;
 
	string s;
	int n;
	bool dp[MAXN][8];
	int prev[MAXN][8];
	cin >> s;
	n = s.size();
	memset(prev, -1, sizeof(prev));
 
    dp[0][(s[0] - '0') % 8] = true;
 
    for (int i = 1; i < n; i++) {
        dp[i][(s[i] - '0') % 8] = true;

        for (int j = 0; j < 8; j++) {
            if (dp[i - 1][j]) {
                dp[i][(j * 10 + s[i] - '0') % 8] = true;
                prev[i][(j * 10 + s[i] - '0') % 8] = j;
 
                dp[i][j] = true;
                prev[i][j] = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (dp[i][0]) {
            string ans = "";
            int curI = i, curJ = 0;
 
            while (true) {
                if (prev[curI][curJ] == -1 || prev[curI][curJ] != curJ) {
                    ans.append(1, s[curI]);
                }
 
                if (prev[curI][curJ] == -1) break;
 
                curJ = prev[curI][curJ];
                curI--;
            }
 
            cout << "YES\n";
            reverse(ALL(ans));
            cout << ans << "\n";
            return 0;
        }
    }
    cout << "NO\n";

	return 0;
}