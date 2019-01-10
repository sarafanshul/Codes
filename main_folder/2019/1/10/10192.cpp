#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    int c = 1;
    while (getline(cin, s), getline(cin, t))
    {
        int dp[101][101] = {};
        for (int i = 1; i <= t.size(); ++i)
            for (int j = 1; j <= s.size(); ++j)
                dp[i][j] = max(dp[i - 1][j - 1] + (t[i - 1] == s[j - 1]),
                               max (dp[i - 1][j], dp[i][j - 1]));

        cout << "Case #" << c++ << ": you can visit at most " << dp[t.size()][s.size()] << " cities.\n";
    }
}
