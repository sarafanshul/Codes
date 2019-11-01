#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[81][81], ind, num;
char par[81][81];
string s, t;

void print(int i, int j)
{
    if (par[i][j] == 'D')
    {
        print(i - 1, j - 1);
        if (t[i - 1] != s[j - 1])
            cout << num++ << " Replace " << ind << ',' << t[i - 1] << '\n';
        ind++;
    }
    else if (par[i][j] == 'U')
    {
        print(i - 1, j);
        cout << num++ << " Insert " << ind++ << ',' << t[i - 1] << '\n';
    }
    else if (par[i][j] == 'L')
    {
        print(i, j - 1);
        cout << num++ << " Delete " << ind << '\n';
    }
}

int main()
{
    int c = 0;
    while (getline(cin, s), getline(cin, t))
    {
        if (c++)
            cout << '\n';
            
        memset(dp, 0, sizeof(dp));
        par[0][0] = '?';
        
        for (int i = 1; i <= s.size(); ++i)
            dp[0][i] = i, par[0][i] = 'L';
        for (int i = 1; i <= t.size(); ++i)
            dp[i][0] = i, par[i][0] = 'U';

        for (int i = 1; i <= t.size(); ++i)
        {
            for (int j = 1; j <= s.size(); ++j)
            {
                dp[i][j] = dp[i - 1][j - 1] + (t[i - 1] != s[j - 1]);
                par[i][j] = 'D';
                if (dp[i - 1][j] + 1 < dp[i][j])
                    dp[i][j] = dp[i - 1][j] + 1, par[i][j] = 'U';
                if (dp[i][j - 1] + 1 < dp[i][j])
                    dp[i][j] = dp[i][j - 1] + 1, par[i][j] = 'L';
            }
        }
        
        ind = 1; num = 1;
        cout << dp[t.size()][s.size()] << '\n';
        print(t.size(), s.size());
    }
}
