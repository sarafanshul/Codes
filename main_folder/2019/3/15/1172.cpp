#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int &b, int x, int &y)
{
    if (a > b || (a == b && x < y))
    {
        b = a; y = x;
        return true;
    }
    
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    int T, n[2];
    cin >> T;
    while (T--)
    {
        vector<vector<string> > os(2);
        vector<vector<int> > val(2);        
        for (int k = 0; k < 2; ++k)
        {
            cin >> n[k];
            os[k].resize(n[k]);
            val[k].resize(n[k]);
            for (int i = 0; i < n[k]; ++i)
                cin >> os[k][i] >> os[k][i] >> val[k][i];
        }
        
        int dp[1001][1001] = {}, c[1001][1001] = {};
        for (int i = 1; i <= n[0]; ++i)
        {
            for (int j = 1; j <= n[1]; ++j)
            {   // LCS maximing the value
                cmp(dp[i - 1][j], dp[i][j], c[i - 1][j], c[i][j]);
                cmp(dp[i][j - 1], dp[i][j], c[i][j - 1], c[i][j]);
                if (os[0][i - 1] == os[1][j - 1] &&
                    cmp(dp[i - 1][j - 1] + val[0][i - 1] + val[1][j - 1], dp[i][j],
                        c[i - 1][j - 1] + 1, c[i][j]));
            }
        }
        
        cout << dp[n[0]][n[1]] << ' ' << c[n[0]][n[1]] << '\n';
    }
}
